#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_REMOVED_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_REMOVED_CALLBACK_HPP_INCLUDED

#include <awl/backends/wayland/system/event/seat_removed_function.hpp>
#include <fcppt/function_impl.hpp>


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
fcppt::function<
	awl::backends::wayland::system::event::seat_removed_function
>
seat_removed_callback;

}
}
}
}
}

#endif
