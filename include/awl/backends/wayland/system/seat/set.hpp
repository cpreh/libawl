#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_SET_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_SET_HPP_INCLUDED

#include <awl/backends/wayland/id_set.hpp>
#include <awl/backends/wayland/system/seat/object.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace seat
{

using
set
=
awl::backends::wayland::id_set<
	awl::backends::wayland::system::seat::object
>;

}
}
}
}
}

#endif
