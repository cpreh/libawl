#ifndef AWL_BACKENDS_WAYLAND_CURSOR_CREATE_NAME_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_CREATE_NAME_HPP_INCLUDED

#include <awl/backends/wayland/cursor/name_fwd.hpp>
#include <awl/backends/wayland/cursor/object_unique_ptr.hpp>
#include <awl/backends/wayland/cursor/theme_fwd.hpp>


namespace awl::backends::wayland::cursor
{

awl::backends::wayland::cursor::object_unique_ptr
create_name(
	awl::backends::wayland::cursor::theme const &,
	awl::backends::wayland::cursor::name const &
);

}

#endif
