#ifndef AWL_BACKENDS_X11_CURSOR_BACKGROUND_COLOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_BACKGROUND_COLOR_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep

namespace awl::backends::x11::cursor
{

FCPPT_DECLARE_STRONG_TYPEDEF(XColor, background_color);

}

#endif
