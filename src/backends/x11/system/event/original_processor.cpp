#include <awl/backends/posix/create_processor.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/backends/posix/extract_event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/flush.hpp>
#include <awl/backends/x11/intern_atom.hpp>
#include <awl/backends/x11/pending.hpp>
#include <awl/backends/x11/system/event/generic.hpp>
#include <awl/backends/x11/system/event/next.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/window/const_optional_object_ref.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/object_ref.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/make.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/event/make_connection.hpp>
#include <awl/event/optional_base_unique_ptr.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/event/close.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/join.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/get_or_insert_with_result.hpp>
#include <fcppt/optional/maybe.hpp>


awl::backends::x11::system::event::original_processor::original_processor(
	awl::backends::x11::display &_display
)
:
	awl::backends::x11::system::event::processor(),
	display_(
		_display
	),
	fd_{
		awl::backends::x11::display_fd(
			_display
		)
	},
	fd_processor_{
		awl::backends::posix::create_processor()
	},
	fd_connection_{
		fd_processor_->register_fd(
			fd_
		)
	},
	wm_protocols_atom_(
		awl::backends::x11::intern_atom(
			_display,
			"WM_PROTOCOLS"
		)
	),
	wm_delete_window_atom_(
		awl::backends::x11::intern_atom(
			_display,
			"WM_DELETE_WINDOW"
		)
	),
	exit_code_(),
	windows_()
{
}

awl::backends::x11::system::event::original_processor::~original_processor()
{
}

awl::system::event::result
awl::backends::x11::system::event::original_processor::poll()
{
	return
		this->process(
			awl::backends::posix::optional_duration{
				awl::backends::posix::duration{
					0
				}
			}
		);
}

awl::system::event::result
awl::backends::x11::system::event::original_processor::next()
{
	return
		this->process(
			awl::backends::posix::optional_duration{}
		);
}

void
awl::backends::x11::system::event::original_processor::quit(
	awl::main::exit_code const _exit_code
)
{
	exit_code_ =
		awl::main::optional_exit_code(
			_exit_code
		);
}

awl::timer::unique_ptr
awl::backends::x11::system::event::original_processor::create_timer(
	awl::timer::setting const &_setting
)
{
	return
		fd_processor_->create_timer(
			_setting
		);
}

awl::backends::posix::processor &
awl::backends::x11::system::event::original_processor::fd_processor()
{
	return
		*fd_processor_;
}

awl::event::connection_unique_ptr
awl::backends::x11::system::event::original_processor::add_window(
	awl::backends::x11::window::object &_window
)
{
	Window const id{
		_window.get()
	};

	FCPPT_ASSERT_ERROR(
		fcppt::container::get_or_insert_with_result(
			windows_,
			id,
			[
				&_window
			](
				Window
			){
				return
					fcppt::make_ref(
						_window
					);
			}
		).inserted()
	);

	return
		awl::event::make_connection(
			awl::event::connection_function{
				[
					this,
					id
				]{
					FCPPT_ASSERT_ERROR(
						windows_.erase(
							id
						)
						==
						1u
					);
				}
			}
		);
}

awl::backends::x11::atom
awl::backends::x11::system::event::original_processor::delete_window_atom() const
{
	return
		wm_delete_window_atom_;
}

awl::system::event::result
awl::backends::x11::system::event::original_processor::process(
	awl::backends::posix::optional_duration const &_duration
) const
{
	return
		fcppt::optional::maybe(
			exit_code_,
			[
				this,
				&_duration
			]{
				return
					awl::system::event::result{
						this->process_fds(
							_duration
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
awl::backends::x11::system::event::original_processor::process_fds(
	awl::backends::posix::optional_duration const &_duration
) const
{
	awl::event::container result{
		awl::backends::x11::pending(
			display_
		)
		> 0u
		?
			this->process_pending()
		:
			awl::event::container{}
	};

	return
		fcppt::algorithm::join(
			std::move(
				result
			),
			awl::backends::posix::extract_event(
				fd_processor_->poll(
					_duration
				),
				fd_,
				fcppt::function<
					awl::event::container ()
				>{
					[
						this
					]{
						awl::backends::x11::flush(
							display_
						);

						return
							this->process_pending();
					}
				}
			)
		);
}

awl::event::container
awl::backends::x11::system::event::original_processor::process_pending() const
{
	return
		fcppt::algorithm::map_optional<
			awl::event::container
		>(
			fcppt::make_int_range_count(
				awl::backends::x11::pending(
					display_
				)
			),
			[
				this
			](
				unsigned
			)
			{
				return
					this->process_x11_event(
						awl::backends::x11::system::event::next(
							display_
						)
					);
			}
		);
}

awl::event::optional_base_unique_ptr
awl::backends::x11::system::event::original_processor::process_x11_event(
	awl::backends::x11::system::event::object const &_event
) const
{
	return
		awl::backends::x11::window::event::filter(
			awl::backends::x11::window::event::object{
				_event.get()
			},
			awl::backends::x11::window::const_optional_object_ref()
		)
		?
			awl::event::optional_base_unique_ptr()
		:
			this->make_x11_event(
				_event
			)
		;
}


awl::event::optional_base_unique_ptr
awl::backends::x11::system::event::original_processor::make_x11_event(
	awl::backends::x11::system::event::object const &_event
) const
{
	return
		_event.get().type
		==
		GenericEvent
		?
			awl::event::optional_base_unique_ptr{
				fcppt::unique_ptr_to_base<
					awl::event::base
				>(
					fcppt::make_unique_ptr<
						awl::backends::x11::system::event::generic
					>(
						fcppt::make_ref(
							display_
						),
						_event.get().xcookie
					)
				)
			}
		:
			fcppt::optional::map(
				fcppt::container::find_opt_mapped(
					windows_,
					_event.get().xany.window
				),
				[
					this,
					&_event
				](
					fcppt::reference<
						awl::backends::x11::window::object_ref const
					> const _window
				)
				{
					return
						this->process_window_event(
							_window.get(),
							awl::backends::x11::window::event::object{
								_event.get()
							}
						);
				}
			)
		;
}

awl::event::base_unique_ptr
awl::backends::x11::system::event::original_processor::process_window_event(
	awl::backends::x11::window::object_ref const _window_ref,
	awl::backends::x11::window::event::object const &_event
) const
{
	return
		_event.get().type
		==
		ClientMessage
		?
			[
				&_event,
				_window_ref,
				this
			]{
				XClientMessageEvent const request(
					_event.get().xclient
				);

				return
					request.message_type
					==
					wm_protocols_atom_.get()
					&&
					static_cast<
						Atom
					>(
						request.data.l[0]
					)
					==
					wm_delete_window_atom_.get()
					?
						fcppt::unique_ptr_to_base<
							awl::event::base
						>(
							fcppt::make_unique_ptr<
								awl::window::event::close
							>(
								fcppt::reference_to_base<
									awl::window::object
								>(
									_window_ref
								)
							)
						)
					:
						awl::backends::x11::window::event::make(
							_window_ref,
							_event
						)
					;
			}()
		:
			awl::backends::x11::window::event::make(
				_window_ref,
				_event
			)
		;
}
