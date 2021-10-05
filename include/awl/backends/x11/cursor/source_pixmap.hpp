#ifndef AWL_BACKENDS_X11_CURSOR_SOURCE_PIXMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_SOURCE_PIXMAP_HPP_INCLUDED

#include <awl/backends/x11/pixmap/const_holder_ref.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl::backends::x11::cursor
{

FCPPT_DECLARE_STRONG_TYPEDEF(
	awl::backends::x11::pixmap::const_holder_ref,
	source_pixmap
);

}

#endif
