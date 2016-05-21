#include <awl/backends/posix/fd.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xlibint.h>
#include <fcppt/config/external_end.hpp>


awl::backends::posix::fd
awl::backends::x11::display_fd(
	awl::backends::x11::display &_display
)
{
	return
		awl::backends::posix::fd{
			_display.get()->fd
		};
}
