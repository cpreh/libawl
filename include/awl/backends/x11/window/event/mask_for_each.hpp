#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_MASK_FOR_EACH_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_MASK_FOR_EACH_HPP_INCLUDED

#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/mask_callback.hpp>


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

void
mask_for_each(
	awl::backends::x11::window::event::mask,
	awl::backends::x11::window::event::mask_callback const &
);

}
}
}
}
}

#endif
