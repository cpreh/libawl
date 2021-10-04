#ifndef AWL_BACKENDS_WAYLAND_WINDOW_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/wayland/window/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl::backends::wayland::window
{

using
object_ref
=
fcppt::reference<
	awl::backends::wayland::window::object
>;

}

#endif
