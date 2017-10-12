#include <awl/backends/posix/fd.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>


awl::backends::posix::fd
awl::backends::wayland::display_fd(
	awl::backends::wayland::display const &_display
)
{
	return
		awl::backends::posix::fd{
			::wl_display_get_fd(
				_display.get()
			)
		};
}
