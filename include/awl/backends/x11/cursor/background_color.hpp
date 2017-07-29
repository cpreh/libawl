#ifndef AWL_BACKENDS_X11_CURSOR_BACKGROUND_COLOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_BACKGROUND_COLOR_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	XColor,
	background_color
);

}
}
}
}

#endif
