#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CHANGE_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CHANGE_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/detail/symbol.hpp>


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

AWL_DETAIL_SYMBOL
void
change_mask(
	awl::backends::x11::window::base &,
	awl::backends::x11::window::event::mask
);

}
}
}
}
}

#endif
