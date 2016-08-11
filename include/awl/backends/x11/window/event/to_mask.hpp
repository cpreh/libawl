#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/event/optional_mask_bit.hpp>
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
awl::backends::x11::window::event::optional_mask_bit
to_mask(
	awl::backends::x11::window::event::type
);

}
}
}
}
}

#endif
