#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::screen
awl::backends::x11::default_screen(
	awl::backends::x11::display_ref const _display
)
{
	return
		awl::backends::x11::screen(
			::XDefaultScreen(
				_display.get().get()
			)
		);
}
