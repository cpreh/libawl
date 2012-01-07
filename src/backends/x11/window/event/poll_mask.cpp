#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/poll_mask.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::optional const
awl::backends::x11::window::event::poll_mask(
	x11::window::instance &_window,
	x11::window::event::mask const _event_mask
)
{
	XEvent ret;

	return
		::XCheckWindowEvent(
			_window.display().get(),
			_window.get(),
			_event_mask.get(),
			&ret
		)
		== True
		?
			x11::window::event::optional(
				x11::window::event::object(
					ret
				)
			)
		:
			x11::window::event::optional();
}