#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/event/next.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::event::object
awl::backends::x11::event::next(
	awl::backends::x11::display &_display
)
{
	XEvent event;

	// always returns 0
	::XNextEvent(
		_display.get(),
		&event
	);

	return
		awl::backends::x11::event::object(
			event
		);
}
