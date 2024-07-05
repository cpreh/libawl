#ifndef AWL_BACKENDS_X11_WINDOW_DELETE_PROPERTY_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_DELETE_PROPERTY_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/property_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::window
{

AWL_DETAIL_SYMBOL
void delete_property(
    awl::backends::x11::window::base const &, awl::backends::x11::window::property);

}

#endif
