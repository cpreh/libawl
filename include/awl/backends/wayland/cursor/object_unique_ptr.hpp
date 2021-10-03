#ifndef AWL_BACKENDS_WAYLAND_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/wayland/cursor/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl::backends::wayland::cursor
{

using
object_unique_ptr
=
fcppt::unique_ptr<
	awl::backends::wayland::cursor::object
>;

}

#endif
