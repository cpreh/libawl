#ifndef AWL_BACKENDS_WAYLAND_CURSOR_OPTIONAL_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_OPTIONAL_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-cursor.h>
#include <fcppt/config/external_end.hpp>


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
	wl_cursor *
>
optional;

}
}
}
}

#endif
