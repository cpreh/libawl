#ifndef AWL_BACKENDS_WAYLAND_CURSOR_CONVERT_NAME_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_CONVERT_NAME_HPP_INCLUDED

#include <awl/backends/wayland/cursor/optional_name.hpp>
#include <awl/cursor/type_fwd.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

awl::backends::wayland::cursor::optional_name
convert_name(
	awl::cursor::type
);

}
}
}
}

#endif
