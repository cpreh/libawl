#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_HANDLER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_HANDLER_HPP_INCLUDED

#include <awl/backends/windows/window/event/object_fwd.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

awl::backends::windows::window::event::return_type
handler(
	awl::backends::windows::window::event::object const &
);

}
}
}
}
}

#endif
