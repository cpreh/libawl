#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/backends/windows/window/event/scoped_processor.hpp>


awl::backends::windows::window::event::scoped_processor::scoped_processor(
	awl::backends::windows::system::event::original_processor &_system_processor,
	awl::backends::windows::window::object &_window,
	awl::backends::windows::window::event::processor &_window_processor
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

awl::backends::windows::window::event::scoped_processor::~scoped_processor()
{
	system_processor_.remove_window_processor(
		window_
	);
}
