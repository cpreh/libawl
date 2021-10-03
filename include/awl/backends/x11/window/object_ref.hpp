#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl::backends::x11::window
{

using
object_ref
=
fcppt::reference<
	awl::backends::x11::window::object
>;

}

#endif
