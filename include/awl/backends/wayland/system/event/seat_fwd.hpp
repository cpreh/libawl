#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_FWD_HPP_INCLUDED

#include <awl/backends/wayland/system/event/add_remove_fwd.hpp>
#include <awl/backends/wayland/system/seat/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

typedef
awl::backends::wayland::system::event::add_remove<
	awl::backends::wayland::system::seat::object
>
seat;

}
}
}
}
}

#endif
