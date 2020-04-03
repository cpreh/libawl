#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/send.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::window::event::send(
	awl::backends::x11::window::base const &_window,
	awl::backends::x11::window::event::mask const _mask,
	awl::backends::x11::window::event::object const &_event
)
{
	if(
		::XSendEvent(
			_window.display().get().get(),
			_window.get(),
			False, // propagate
			_mask.get(),
			// NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
			const_cast<
				XEvent *
			>(
				&_event.get()
			)
		)
		== 0
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("XSendEvent() failed!")
			};
	}
}
