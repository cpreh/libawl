#include <awl/exception.hpp>
#include <awl/backends/wayland/shell.hpp>
#include <awl/backends/wayland/surface.hpp>
#include <awl/backends/wayland/window/shell_surface.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::window::shell_surface::shell_surface(
	awl::backends::wayland::shell const &_shell,
	awl::backends::wayland::surface const &_surface
)
:
	impl_{
		::wl_shell_get_shell_surface(
			_shell.get(),
			_surface.get()
		)
	}
{
	if(
		impl_
		==
		nullptr
	)
		throw
			awl::exception{
				FCPPT_TEXT("Failed getting a shell surface")
			};
}

awl::backends::wayland::window::shell_surface::~shell_surface()
{
	::wl_shell_surface_destroy(
		impl_
	);
}

wl_shell_surface *
awl::backends::wayland::window::shell_surface::get() const
{
	return
		impl_;
}
