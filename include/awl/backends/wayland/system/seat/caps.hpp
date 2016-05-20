#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps_fwd.hpp>


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

enum class caps
{
	pointer,
	focus,
	fcppt_maximum = focus
};

}
}
}
}
}

#endif
