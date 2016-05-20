#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_FIELD_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_FIELD_FWD_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>


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

typedef
fcppt::container::bitfield::object_from_enum<
	awl::backends::wayland::system::seat::caps
>
caps_field;

}
}
}
}
}

#endif
