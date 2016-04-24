#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_UNREGISTER_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_UNREGISTER_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor_fwd.hpp>
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
	void (
		awl::backends::x11::window::event::processor &
	)
>
unregister_callback;

}
}
}
}
}

#endif
