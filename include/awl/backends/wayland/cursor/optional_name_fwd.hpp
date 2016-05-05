#ifndef AWL_BACKENDS_WAYLAND_CURSOR_OPTIONAL_NAME_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_OPTIONAL_NAME_FWD_HPP_INCLUDED

#include <awl/backends/wayland/cursor/name_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

typedef
fcppt::optional::object<
	awl::backends::wayland::cursor::name
>
optional_name;

}
}
}
}

#endif
