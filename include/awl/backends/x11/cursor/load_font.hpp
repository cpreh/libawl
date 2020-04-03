#ifndef AWL_BACKENDS_X11_CURSOR_LOAD_FONT_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_LOAD_FONT_HPP_INCLUDED

#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/shape.hpp>
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
awl::backends::x11::cursor::holder_unique_ptr
load_font(
	awl::backends::x11::display_ref,
	awl::backends::x11::cursor::shape
);

}
}
}
}

#endif
