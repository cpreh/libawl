#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_CREATE_WINDOW_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_CREATE_WINDOW_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor_unique_ptr.hpp>
#include <awl/backends/x11/window/event/unregister_callback.hpp>
#include <awl/window/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

awl::backends::x11::window::event::processor_unique_ptr
create_window_processor(
	awl::window::object &,
	awl::backends::x11::window::event::unregister_callback
);

}
}
}
}
}

#endif
