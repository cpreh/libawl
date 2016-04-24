#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

typedef
fcppt::unique_ptr<
	awl::backends::x11::window::event::processor
>
processor_unique_ptr;

}
}
}
}
}

#endif
