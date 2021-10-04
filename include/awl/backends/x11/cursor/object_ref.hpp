#ifndef AWL_BACKENDS_X11_CURSOR_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/x11/cursor/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl::backends::x11::cursor
{

using
object_ref
=
fcppt::reference<
	awl::backends::x11::cursor::object
>;

}

#endif
