#ifndef AWL_BACKENDS_X11_PENDING_HPP_INCLUDED
#define AWL_BACKENDS_X11_PENDING_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11
{

AWL_DETAIL_SYMBOL
unsigned
pending(
	awl::backends::x11::display const &
);

}

#endif
