#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_FIELD_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_FIELD_FWD_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps.hpp>
#include <fcppt/container/bitfield/enum_object_fwd.hpp>


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
fcppt::container::bitfield::enum_object<
	awl::backends::wayland::system::seat::caps
>
caps_field;

}
}
}
}
}

#endif
