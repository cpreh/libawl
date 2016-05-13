#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/backends/x11/window/event/scoped_processor.hpp>


awl::backends::x11::window::event::scoped_processor::scoped_processor(
	awl::backends::x11::system::event::original_processor &_system_processor,
	awl::backends::x11::window::object &_window,
	awl::backends::x11::window::event::processor &_window_processor
)
:
	system_processor_{
		_system_processor
	},
	window_{
		_window
	}
{
	system_processor_.add_window_processor(
		window_,
		_window_processor
	);
}

awl::backends::x11::window::event::scoped_processor::~scoped_processor()
{
	system_processor_.remove_window_processor(
		window_
	);
}
