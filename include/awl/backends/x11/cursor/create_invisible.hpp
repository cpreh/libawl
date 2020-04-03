#ifndef AWL_BACKENDS_X11_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED

#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/cursor/object_unique_ptr.hpp>
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
awl::backends::x11::cursor::object_unique_ptr
create_invisible(
	awl::backends::x11::display_ref
);

}
}
}
}

#endif
