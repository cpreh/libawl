#ifndef AWL_BACKENDS_WAYLAND_WINDOW_SHELL_SURFACE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_SHELL_SURFACE_HPP_INCLUDED

#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/surface_fwd.hpp>
#include <awl/backends/wayland/window/shell_surface_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace window
{

class shell_surface
{
	FCPPT_NONCOPYABLE(
		shell_surface
	);
public:
	shell_surface(
		awl::backends::wayland::shell const &,
		awl::backends::wayland::surface const &
	);

	~shell_surface();

	wl_shell_surface *
	get() const;
private:
	wl_shell_surface *impl_;
};

}
}
}
}

#endif
