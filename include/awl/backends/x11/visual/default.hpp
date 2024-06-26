#ifndef AWL_BACKENDS_X11_VISUAL_DEFAULT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_DEFAULT_HPP_INCLUDED

#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::visual
{

AWL_DETAIL_SYMBOL
awl::backends::x11::visual::object_unique_ptr
    default_(awl::backends::x11::display_ref, awl::backends::x11::screen);

}

#endif
