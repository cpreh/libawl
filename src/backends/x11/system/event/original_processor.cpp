#include <awl/backends/linux/fd/duration.hpp>
#include <awl/backends/linux/fd/event_fwd.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/optional_duration.hpp>
#include <awl/backends/linux/fd/original_processor.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/flush.hpp>
#include <awl/backends/x11/pending.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/create_window_processor.hpp>
#include <awl/backends/x11/system/event/generic.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/next.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/processor_unique_ptr.hpp>
#include <awl/backends/x11/window/event/unregister_callback.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/quit.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <awl/window/object.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <functional>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::event::original_processor::original_processor(
	awl::backends::x11::display &_display
)
:
	awl::backends::x11::system::event::processor(),
	awl::backends::linux::fd::original_processor(),
	display_(
		_display
	),
	signals_(),
	fd_connection_{
		this->register_fd_callback(
			awl::backends::linux::fd::object(
				awl::backends::x11::display_fd(
					_display
				)
			),
			awl::backends::linux::fd::callback{
				std::bind(
					&awl::backends::x11::system::event::original_processor::process_pending,
					this,
					std::placeholders::_1
				)
			}
		)
	},
	exit_code_(),
	quit_signal_(),
	window_processors_()
{
}

awl::backends::x11::system::event::original_processor::~original_processor()
{
}

awl::main::optional_exit_code
awl::backends::x11::system::event::original_processor::poll()
{
	this->epoll(
		awl::backends::linux::fd::optional_duration(
			awl::backends::linux::fd::duration(
				0
			)
		)
	);

	return
		exit_code_;
}

awl::main::optional_exit_code
awl::backends::x11::system::event::original_processor::next()
{
	this->epoll(
		awl::backends::linux::fd::optional_duration()
	);

	return
		exit_code_;
}

awl::window::event::processor_unique_ptr
awl::backends::x11::system::event::original_processor::create_window_processor(
	awl::window::object &_window
)
{
	awl::backends::x11::window::event::processor_unique_ptr processor{
		awl::backends::x11::system::event::create_window_processor(
			_window,
			awl::backends::x11::window::event::unregister_callback{
				[
					this
				](
					awl::backends::x11::window::event::processor &_processor
				)
				{
					FCPPT_ASSERT_ERROR(
						window_processors_.erase(
							_processor.x11_window().get()
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
				processor->x11_window().get(),
				fcppt::make_ref(
					*processor
				)
			)
		).second
	);

	return
		fcppt::unique_ptr_to_base<
			awl::window::event::processor
		>(
			std::move(
				processor
			)
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

	// TODO: can we integrate this in the message loop instead?
	quit_signal_(
		awl::system::event::quit(
			_exit_code
		)
	);
}

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::quit_callback(
	awl::system::event::quit_callback const &_callback
)
{
	return
		quit_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::register_callback(
	awl::backends::x11::system::event::opcode const &_opcode,
	awl::backends::x11::system::event::type const &_type,
	awl::backends::x11::system::event::callback const &_callback
)
{
	return
		signals_[
			awl::backends::x11::system::event::map_key(
				_opcode,
				_type
			)
		].connect(
			_callback
		);
}

void
awl::backends::x11::system::event::original_processor::process_pending(
	awl::backends::linux::fd::event const &
)
{
	while(
		awl::backends::x11::pending(
			display_
		)
		>
		0u
	)
		this->process_event(
			awl::backends::x11::system::event::next(
				display_
			)
		);

	awl::backends::x11::flush(
		display_
	);
}

void
awl::backends::x11::system::event::original_processor::process_event(
	awl::backends::x11::system::event::object const &_event
)
{
	if(
		_event.get().type
		==
		GenericEvent
	)
	{
		XGenericEventCookie const &generic_event(
			_event.get().xcookie
		);

		signals_[
			awl::backends::x11::system::event::map_key(
				awl::backends::x11::system::event::opcode(
					generic_event.extension
				),
				awl::backends::x11::system::event::type(
					generic_event.evtype
				)
			)
		](
			awl::backends::x11::system::event::generic{
				generic_event
			}
		);
	}
	else
	{
		fcppt::optional::maybe_void(
			fcppt::container::find_opt_mapped(
				window_processors_,
				_event.get().xany.window
			),
			[
				&_event
			](
				fcppt::reference<
					fcppt::reference<
						awl::backends::x11::window::event::processor
					>
				> const _processor
			)
			{
				_processor.get().get().process(
					awl::backends::x11::window::event::object{
						_event.get()
					}
				);
			}
		);
	}
}
