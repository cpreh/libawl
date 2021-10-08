#ifndef AWL_BACKENDS_WAYLAND_CURSOR_CONVERT_NAME_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_CONVERT_NAME_HPP_INCLUDED

#include <awl/backends/wayland/cursor/name.hpp>
#include <awl/cursor/type_fwd.hpp>

namespace awl::backends::wayland::cursor
{

awl::backends::wayland::cursor::name convert_name(awl::cursor::type);

}

#endif
