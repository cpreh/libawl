#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::window::event::change_mask(
	awl::backends::x11::window::base const &_window,
	awl::backends::x11::window::event::mask const _mask
)
{
	if(
		_window.destroyed()
	)
	{
		return;
	}

	// Always returns 1
	::XSelectInput(
		_window.display().get().get(),
		_window.get(),
		_mask.get()
	);
}
