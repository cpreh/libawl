#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SEND_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SEND_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
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
send(
	x11::window::object const &,
	x11::window::event::mask,
	x11::window::event::object const &
);

}
}
}
}
}

#endif
