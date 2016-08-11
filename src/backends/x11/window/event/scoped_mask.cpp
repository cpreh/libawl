#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/scoped_mask.hpp>


awl::backends::x11::window::event::scoped_mask::scoped_mask(
	awl::backends::x11::window::event::processor &_processor,
	awl::backends::x11::window::event::mask const _mask
)
:
	processor_{
		_processor
	},
	mask_{
		_mask
	}
{
	processor_.add_event_mask(
		mask_
	);
}

awl::backends::x11::window::event::scoped_mask::~scoped_mask()
{
	processor_.remove_event_mask(
		mask_
	);
}
