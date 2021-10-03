#ifndef AWL_BACKENDS_X11_CURSOR_FOREGROUND_COLOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_FOREGROUND_COLOR_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl::backends::x11::cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	XColor,
	foreground_color
);

}

#endif
