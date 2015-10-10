#ifndef AWL_BACKENDS_X11_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED

#include <awl/backends/x11/cursor/shape.hpp>
#include <awl/cursor/predefined_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

AWL_DETAIL_SYMBOL
awl::backends::x11::cursor::shape
convert_predefined(
	awl::cursor::predefined
);

}
}
}
}

#endif
