#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


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

typedef
fcppt::unique_ptr<
	awl::backends::windows::window::event::processor
>
processor_unique_ptr;

}
}
}
}
}

#endif
