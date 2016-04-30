#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/window/event/processor_unique_ptr.hpp>
#include <awl/backends/windows/window/event/unregister_callback.hpp>
#include <awl/window/object_fwd.hpp>


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

awl::backends::windows::window::event::processor_unique_ptr
create_processor(
	awl::window::object &,
	awl::backends::windows::window::event::unregister_callback const &
);

}
}
}
}
}

#endif
