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
awl::backends::x11::window::event::optional
poll_type(
	awl::backends::x11::window::object &,
	awl::backends::x11::window::event::type
);

}
}
}
}
}

#endif
