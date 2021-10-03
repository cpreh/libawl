#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_FILTER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_FILTER_HPP_INCLUDED

#include <awl/backends/x11/window/const_optional_object_ref_fwd.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11::window::event
{

[[nodiscard]]
AWL_DETAIL_SYMBOL
bool
filter(
	awl::backends::x11::window::event::object,
	awl::backends::x11::window::const_optional_object_ref
);

}

#endif
