#include <awl/exception.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/peek_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_destroy_callback.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/create_processor.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/processor_unique_ptr.hpp>
#include <awl/backends/windows/window/event/unregister_callback.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/remove.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::system::event::original_processor::original_processor()
:
	awl::backends::windows::system::event::processor(),
	signals_(),
	handle_signal_(),
	handles_(),
	window_processors_()
{
}

awl::backends::windows::system::event::original_processor::~original_processor()
{
}

awl::main::optional_exit_code
awl::backends::windows::system::event::original_processor::poll()
{
	this->generic_multiple_wait(
		::WaitForMultipleObjects,
		0u
	);

	return
		this->poll_messages();

}

awl::main::optional_exit_code
awl::backends::windows::system::event::original_processor::next()
{
	this->generic_multiple_wait(
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
		},
		INFINITE
	);

	return
		this->poll_messages();
}

awl::window::event::processor_unique_ptr
awl::backends::windows::system::event::original_processor::create_window_processor(
	awl::window::object &_window
)
{
	awl::backends::windows::window::event::processor_unique_ptr result{
		awl::backends::windows::window::event::create_processor(
			_window,
			awl::backends::windows::window::event::unregister_callback{
				[
					this
				](
					awl::backends::windows::window::event::processor &_processor
				)
				{
					FCPPT_ASSERT_ERROR(
						window_processors_.erase(
							_processor.windows_window().hwnd()
						)
						==
						1u
					);
				}
			}
		)
	};

	FCPPT_ASSERT_ERROR(
		window_processors_.insert(
			std::make_pair(
				result->windows_window().hwnd(),
				fcppt::make_ref(
					*result
				)
			)
		).second
	);

	return
		fcppt::unique_ptr_to_base<
			awl::window::event::processor
		>(
			std::move(
				result
			)
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

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_callback(
	awl::backends::windows::message_type const _msg,
	awl::backends::windows::system::event::callback const &_func
)
{
	return
		signals_[
			_msg
		].connect(
			_func
		);
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_handle_callback(
	awl::backends::windows::system::event::handle_callback const &_func
)
{
	return
		handle_signal_.connect(
			_func
		);
}

awl::backends::windows::system::event::handle_unique_ptr
awl::backends::windows::system::event::original_processor::create_event_handle()
{
	awl::backends::windows::system::event::handle_unique_ptr ret(
		fcppt::unique_ptr_to_base<
			awl::backends::windows::system::event::handle
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::system::event::original_handle
			>(
				awl::backends::windows::system::event::handle_destroy_callback{
					[
						this
					](
						HANDLE const _handle
					)
					{
						FCPPT_ASSERT_ERROR(
							fcppt::algorithm::remove(
								handles_,
								_handle
							)
						);
					}
				}
			)
		)
	);

	handles_.push_back(
		ret->get()
	);

	return
		ret;
}

awl::main::optional_exit_code
awl::backends::windows::system::event::original_processor::poll_messages()
{
	// TODO: This is ugly
	awl::main::optional_exit_code result;

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
				result =
					fcppt::optional::alternative(
						this->process_message(
							_message
						),
						std::move(
							result
						)
					);

				return
					true;
			}
		)
	)
		;

	return
		result;
}

awl::main::optional_exit_code
awl::backends::windows::system::event::original_processor::process_message(
	awl::backends::windows::message const &_msg
)
{
	if(
		_msg.get().hwnd
		==
		NULL
	)
		signals_[
			awl::backends::windows::message_type{
				_msg.get().message
			}
		](
			awl::backends::windows::system::event::object{
				awl::backends::windows::wparam{
					_msg.get().wParam
				},
				awl::backends::windows::lparam{
					_msg.get().lParam
				}
			}
		);
	else
		fcppt::optional::maybe_void(
			fcppt::optional::copy_value(
				fcppt::container::find_opt_mapped(
					window_processors_,
					_msg.get().hwnd
				)
			),
			[
				&_msg
			](
				window_processor_ref const _processor
			)
			{
				_processor.get().process(
					_msg
				);
			}
		);

	if(
		_msg.get().message
		==
		WM_QUIT
	)
	{
		awl::main::exit_code const res_exit_code(
			fcppt::cast::size<
				int
			>(
				fcppt::cast::to_signed(
					_msg.get().wParam
				)
			)
		);

		return
			awl::main::optional_exit_code{
				res_exit_code
			};
	}

	return
		awl::main::optional_exit_code{};
}

template<
	typename Function
>
void
awl::backends::windows::system::event::original_processor::generic_multiple_wait(
	Function const _function,
	DWORD const _timeout
)
{
	DWORD const result(
		_function(
			fcppt::cast::size<
				DWORD
			>(
				handles_.size()
			),
			handles_.data(),
			FALSE,
			_timeout
		)
	);

	static_assert(
		WAIT_OBJECT_0 == 0,
		"This code assumes that WAIT_OBJECT_0 is 0"
	);

	if(
		result
		<
		WAIT_OBJECT_0 + handles_.size()
	)
		handle_signal_();
	else if(
		result
		==
		WAIT_FAILED
	)
		throw
			awl::exception{
				FCPPT_TEXT("WaitForMultipleObjects() failed!")
			};
}


