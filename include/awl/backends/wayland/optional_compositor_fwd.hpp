#ifndef AWL_BACKENDS_WAYLAND_OPTIONAL_COMPOSITOR_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_OPTIONAL_COMPOSITOR_FWD_HPP_INCLUDED

#include <awl/backends/wayland/compositor_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

typedef
fcppt::optional::object<
	awl::backends::wayland::compositor
>
optional_compositor;

}
}
}

#endif
