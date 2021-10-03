#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_NEXT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_NEXT_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11::system::event
{

AWL_DETAIL_SYMBOL
awl::backends::x11::system::event::object
next(
	awl::backends::x11::display const &
);

}

#endif
