#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/window/event/function.hpp>
#include <fcppt/function_impl.hpp>


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
fcppt::function<
	awl::backends::x11::window::event::function
>
callback;

}
}
}
}
}

#endif
