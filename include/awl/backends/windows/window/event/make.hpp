#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_MAKE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_MAKE_HPP_INCLUDED

#include <awl/event/base_unique_ptr.hpp>
#include <awl/backends/windows/system/event/object_fwd.hpp>
#include <awl/backends/windows/window/reference.hpp>


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

awl::event::base_unique_ptr
make(
	awl::backends::windows::window::reference,
	awl::backends::windows::system::event::object const &
);

}
}
}
}
}

#endif