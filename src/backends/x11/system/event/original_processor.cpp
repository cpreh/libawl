#include <awl/backends/posix/create_processor.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/backends/posix/event_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/flush.hpp>
#include <awl/backends/x11/pending.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/generic.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/next.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/backends/x11/window/const_optional_object_ref.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/window/object.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
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
	display_(
		_display
	),
	fd_processor_{
		awl::backends::posix::create_processor()
	},
	signals_(),
	fd_connection_{
		fd_processor_->register_fd_callback(
			awl::backends::x11::display_fd(
				_display
			),
			awl::backends::posix::callback{
				std::bind(
					&awl::backends::x11::system::event::original_processor::process_pending,
					this,
					std::placeholders::_1
				)
			}
		)
	},
	exit_code_(),
	window_processors_()
{
}

awl::backends::x11::system::event::original_processor::~original_processor()
{
}

awl::main::optional_exit_code
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

awl::main::optional_exit_code
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

awl::backends::posix::processor &
awl::backends::x11::system::event::original_processor::fd_processor()
{
	return
		*fd_processor_;
}

void
awl::backends::x11::system::event::original_processor::add_window_processor(
	awl::backends::x11::window::object &_window,
	awl::backends::x11::window::event::processor &_processor
)
{
	FCPPT_ASSERT_ERROR(
		window_processors_.insert(
			std::make_pair(
				_window.get(),
				fcppt::make_ref(
					_processor
				)
			)
		).second
	);
}

void
awl::backends::x11::system::event::original_processor::remove_window_processor(
	awl::backends::x11::window::object const &_window
)
{
	FCPPT_ASSERT_ERROR(
		window_processors_.erase(
			_window.get()
		)
		==
		1u
	);
}

awl::main::optional_exit_code
awl::backends::x11::system::event::original_processor::process(
	awl::backends::posix::optional_duration const &_duration
)
{
	fd_processor_->poll(
		_duration
	);

	return
		exit_code_;
}

void
awl::backends::x11::system::event::original_processor::process_pending(
	awl::backends::posix::event const &
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
		awl::backends::x11::window::event::filter(
			awl::backends::x11::window::event::object{
				_event.get()
			},
			awl::backends::x11::window::const_optional_object_ref()
		)
	)
		return;

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
