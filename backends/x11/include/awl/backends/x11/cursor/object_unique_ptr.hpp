#ifndef AWL_BACKENDS_X11_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/cursor/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl::backends::x11::cursor
{

using object_unique_ptr = fcppt::unique_ptr<awl::backends::x11::cursor::object>;

}

#endif
