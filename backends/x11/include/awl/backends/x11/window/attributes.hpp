#ifndef AWL_BACKENDS_X11_WINDOW_ATTRIBUTES_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ATTRIBUTES_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::window
{

AWL_DETAIL_SYMBOL
XWindowAttributes attributes(awl::backends::x11::window::base const &);

}

#endif
