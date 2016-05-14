#ifndef AWL_BACKENDS_WAYLAND_SEAT_SET_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SEAT_SET_HPP_INCLUDED

#include <awl/backends/wayland/registry_set.hpp>
#include <awl/backends/wayland/seat.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

typedef
awl::backends::wayland::registry_set<
	awl::backends::wayland::seat
>
seat_set;

}
}
}

#endif
