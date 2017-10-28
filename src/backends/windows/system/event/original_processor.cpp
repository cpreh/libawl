#include <awl/exception.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/peek_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/system/event/generic.hpp>
#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_holder.hpp>
#include <awl/backends/windows/system/event/handle_holder_unique_ptr.hpp>
#include <awl/backends/windows/system/event/handle_ready.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/timer/object.hpp>
#include <awl/backends/windows/timer/waitable.hpp>
#include <awl/backends/windows/timer/waitable_unique_ptr.hpp>
#include <awl/backends/windows/window/get_user_data.hpp>
#include <awl/backends/windows/window/event/make.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/make_connection.hpp>
#include <awl/event/optional_base_unique_ptr.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/identity.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/algorithm/remove.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/insert.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::system::event::original_processor::original_processor()
:
	awl::backends::windows::system::event::processor(),
	handles_(),
	user_messages_(
		// TODO: We need something better for this, like a sparse map
		fcppt::algorithm::map<
			user_message_vector
		>(
			fcppt::make_int_range(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_USER
				),
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_USER
					+
					128
				)
			),
			fcppt::identity{}
		)
	),
	timers_{},
	exit_code_{}
{
}

awl::backends::windows::system::event::original_processor::~original_processor()
{
}

awl::system::event::result
awl::backends::windows::system::event::original_processor::poll()
{
	return
		this->process(
			handle_function{
				[](
					DWORD const _count,
					HANDLE const *const _handle,
					BOOL const _wait_all,
					DWORD const _milli_seconds
				)
				{
					return
						::WaitForMultipleObjects(
							_count,
							_handle,
							_wait_all,
							_milli_seconds
						);
				}
			},
			timeout{
				0u
			}
		);
}

awl::system::event::result
awl::backends::windows::system::event::original_processor::next()
{
	return
		this->process(
			handle_function{
				[](
					DWORD const _count,
					HANDLE const *const _handle,
					BOOL const _wait_all,
					DWORD const _milli_seconds
				)
				{
					return
						::MsgWaitForMultipleObjects(
							_count,
							_handle,
							_wait_all,
							_milli_seconds,
							QS_ALLPOSTMESSAGE
						);
				}
			},
			timeout{
				INFINITE
			}
		);
}

void
awl::backends::windows::system::event::original_processor::quit(
	awl::main::exit_code const _exit_code
)
{
	::PostQuitMessage(
		_exit_code.get()
	);
}

awl::timer::unique_ptr
awl::backends::windows::system::event::original_processor::create_timer(
	awl::timer::setting const &_setting
)
{
	awl::backends::windows::timer::waitable_unique_ptr timer{
		fcppt::make_unique_ptr<
			awl::backends::windows::timer::waitable
		>()
	};

	HANDLE const handle{
		timer->handle()
	};

	awl::event::connection_unique_ptr connection{
		awl::event::make_connection(
			awl::event::connection_function{
				[
					handle,
					this
				]{
					this->remove_handle(
						handle
					);

					this->timers_.erase(
						handle
					);
				}
			}
		)
	};

	awl::timer::unique_ptr result{
		fcppt::unique_ptr_to_base<
			awl::timer::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::timer::object
			>(
				_setting,
				std::move(
					timer
				),
				std::move(
					connection
				)
			)
		)
	};

	handles_.push_back(
		handle
	);

	FCPPT_ASSERT_ERROR(
		fcppt::container::insert(
			timers_,
			timer_map::value_type{
				handle,
				fcppt::make_ref(
					*result
				)
			}
		)
	);

	return
		result;

}

awl::backends::windows::system::event::handle_unique_ptr
awl::backends::windows::system::event::original_processor::create_event_handle()
{
	awl::backends::windows::system::event::handle_holder_unique_ptr holder{
		fcppt::make_unique_ptr<
			awl::backends::windows::system::event::handle_holder
		>()
	};

	HANDLE const handle{
		holder->get()
	};

	awl::event::connection_unique_ptr connection{
		awl::event::make_connection(
			awl::event::connection_function{
				[
					handle,
					this
				]{
					this->remove_handle(
						handle
					);
				}
			}
		)
	};

	handles_.push_back(
		handle
	);

	return
		fcppt::unique_ptr_to_base<
			awl::backends::windows::system::event::handle
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::system::event::original_handle
			>(
				std::move(
					holder
				),
				std::move(
					connection
				)
			)
		);
}

awl::backends::windows::message_type
awl::backends::windows::system::event::original_processor::allocate_user_message()
{
	return
		fcppt::optional::to_exception(
			fcppt::container::pop_back(
				user_messages_
			),
			[]{
				return
					awl::exception{
						FCPPT_TEXT("User messages exhausted.")
					};
			}
		);
}

void
awl::backends::windows::system::event::original_processor::free_user_message(
	awl::backends::windows::message_type const _message
)
{
	user_messages_.push_back(
		_message
	);
}

awl::system::event::result
awl::backends::windows::system::event::original_processor::process(
	handle_function const &_handler,
	timeout const _timeout
)
{
	return
		fcppt::optional::maybe(
			exit_code_,
			[
				&_handler,
				_timeout,
				this
			]{
				return
					awl::system::event::result{
						this->generic_multiple_wait(
							_handler,
							_timeout
						)
					};
			},
			[](
				awl::main::exit_code const _code
			)
			{
				return
					awl::system::event::result{
						_code
					};
			}
		);
}

awl::event::container
awl::backends::windows::system::event::original_processor::poll_messages()
{
	// TODO: Make a range for this.
	awl::event::container result;

	while(
		fcppt::optional::maybe(
			awl::backends::windows::peek_message(
				NULL
			),
			fcppt::const_(
				false
			),
			[
				&result,
				this
			](
				awl::backends::windows::message const &_message
			)
			{
				::TranslateMessage(
					&_message.get()
				);

				::DispatchMessage(
					&_message.get()
				);

				return
					fcppt::optional::maybe(
						this->process_message(
							_message
						),
						fcppt::const_(
							false
						),
						[
							&result
						](
							awl::event::base_unique_ptr &&_event
						){
							result.push_back(
								std::move(
									_event
								)
							);

							return
								true;
						}
					);
			}
		)
	)
		;

	return
		result;
}

awl::event::optional_base_unique_ptr
awl::backends::windows::system::event::original_processor::process_message(
	awl::backends::windows::message const &_msg
)
{
	if(
		_msg.get().message
		==
		WM_QUIT
	)
	{
		exit_code_ =
			awl::main::optional_exit_code{
				awl::main::exit_code{
					fcppt::cast::size<
						int
					>(
						fcppt::cast::to_signed(
							_msg.get().wParam
						)
					)
				}
			};

		return
			awl::event::optional_base_unique_ptr{};
	}

	return
		awl::event::optional_base_unique_ptr{
			this->make_message(
				_msg
			)
		};
}

awl::event::base_unique_ptr
awl::backends::windows::system::event::original_processor::make_message(
	awl::backends::windows::message const &_msg
)
{
	awl::backends::windows::system::event::object const event{
		awl::backends::windows::message_type{
			_msg.get().message
		},
		awl::backends::windows::wparam{
			_msg.get().wParam
		},
		awl::backends::windows::lparam{
			_msg.get().lParam
		}
	};

	return
		_msg.get().hwnd
		==
		NULL
		?
			fcppt::unique_ptr_to_base<
				awl::event::base
			>(
				fcppt::make_unique_ptr<
					awl::backends::windows::system::event::generic
				>(
					event
				)
			)
		:
			awl::backends::windows::window::event::make(
				awl::backends::windows::window::get_user_data(
					_msg.get().hwnd
				),
				event
			)
		;
}

awl::system::event::result
awl::backends::windows::system::event::original_processor::generic_multiple_wait(
	handle_function const &_function,
	timeout const _timeout
)
{
	DWORD const count{
		fcppt::cast::size<
			DWORD
		>(
			handles_.size()
		)
	};

	DWORD const result(
		_function(
			count,
			handles_.data(),
			FALSE,
			_timeout.get()
		)
	);

	static_assert(
		WAIT_OBJECT_0 == 0,
		"This code assumes that WAIT_OBJECT_0 is 0"
	);

	if(
		result
		==
		WAIT_FAILED
	)
		throw
			awl::exception{
				FCPPT_TEXT("WaitForMultipleObjects() failed!")
			};

	return
		awl::system::event::result{
			result
			==
			WAIT_OBJECT_0
			+
			count
			?
				this->poll_messages()
			:
				result
				<
				WAIT_OBJECT_0
				+
				handles_.size()
				?
					fcppt::assign::make_container<
						awl::event::container
					>(
						this->handle_event(
							result
							-
							WAIT_OBJECT_0
						)
					)
				:
					awl::event::container{}
		};
}

awl::event::base_unique_ptr
awl::backends::windows::system::event::original_processor::handle_event(
	DWORD const _index
)
{
	HANDLE const handle{
		handles_[
			_index
		]
	};

	return
		fcppt::optional::maybe(
			fcppt::container::find_opt_mapped(
				timers_,
				handle
			),
			[
				handle
			]{
				return
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::backends::windows::system::event::handle_ready
						>(
							handle
						)
					);
			},
			[](
				fcppt::reference<
					awl::timer::reference
				> const _ref
			)
			{
				return
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::timer::event
						>(
							_ref.get()
						)
					);
			}
		);
}

void
awl::backends::windows::system::event::original_processor::remove_handle(
	HANDLE const _handle
)
{
	fcppt::algorithm::remove(
		handles_,
		_handle
	);
}
