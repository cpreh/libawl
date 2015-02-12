#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_POLL_TYPE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_POLL_TYPE_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/optional.hpp>
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
x11::window::event::optional const
poll_type(
	x11::window::object &,
	x11::window::event::type
);

}
}
}
}
}

#endif
