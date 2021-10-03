#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_FIELD_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_FIELD_FWD_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>


namespace awl::backends::wayland::system::seat
{

using
caps_field
=
fcppt::container::bitfield::object<
	awl::backends::wayland::system::seat::caps
>;

}

#endif
