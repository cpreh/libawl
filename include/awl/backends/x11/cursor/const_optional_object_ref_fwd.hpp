#ifndef AWL_BACKENDS_X11_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/backends/x11/cursor/object_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>

namespace awl::backends::x11::cursor
{

using const_optional_object_ref =
    fcppt::optional::reference<awl::backends::x11::cursor::object const>;

}

#endif
