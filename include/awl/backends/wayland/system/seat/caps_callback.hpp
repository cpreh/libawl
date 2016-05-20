#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_CALLBACK_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps_function.hpp>
#include <fcppt/function_impl.hpp>


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
fcppt::function<
	awl::backends::wayland::system::seat::caps_function
>
caps_callback;

}
}
}
}
}

#endif
