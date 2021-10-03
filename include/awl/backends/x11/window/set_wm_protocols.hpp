#ifndef AWL_BACKENDS_X11_WINDOW_SET_WM_PROTOCOLS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_SET_WM_PROTOCOLS_HPP_INCLUDED

#include <awl/backends/x11/window/atoms_fwd.hpp>
#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11::window
{

AWL_DETAIL_SYMBOL
void
set_wm_protocols(
	awl::backends::x11::window::base const &,
	awl::backends::x11::window::atoms const &
);

}

#endif
