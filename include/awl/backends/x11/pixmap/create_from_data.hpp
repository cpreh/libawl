#ifndef AWL_BACKENDS_X11_PIXMAP_CREATE_FROM_DATA_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_CREATE_FROM_DATA_HPP_INCLUDED

#include <awl/backends/x11/pixmap/dim_fwd.hpp>
#include <awl/backends/x11/pixmap/holder_unique_ptr.hpp>
#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::pixmap
{

AWL_DETAIL_SYMBOL
awl::backends::x11::pixmap::holder_unique_ptr create_from_data(
    awl::backends::x11::window::base const &,
    awl::backends::x11::pixmap::dim const &,
    char const *);

}

#endif
