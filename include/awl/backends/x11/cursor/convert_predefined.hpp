#ifndef AWL_BACKENDS_X11_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED

#include <awl/backends/x11/cursor/shape.hpp>
#include <awl/cursor/type_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11::cursor
{

AWL_DETAIL_SYMBOL
awl::backends::x11::cursor::shape
convert_predefined(
	awl::cursor::type
);

}

#endif
