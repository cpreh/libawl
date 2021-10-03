#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SEND_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SEND_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11::window::event
{

AWL_DETAIL_SYMBOL
void
send(
	awl::backends::x11::window::base const &,
	awl::backends::x11::window::event::mask,
	awl::backends::x11::window::event::object const &
);

}

#endif
