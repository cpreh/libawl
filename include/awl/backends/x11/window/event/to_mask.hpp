#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/event/optional_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
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
event::optional_mask const
to_mask(
	x11::window::event::type
);

}
}
}
}
}

#endif
