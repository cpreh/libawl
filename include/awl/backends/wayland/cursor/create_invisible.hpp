#ifndef AWL_BACKENDS_WAYLAND_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED

#include <awl/backends/wayland/shm_fwd.hpp>
#include <awl/backends/wayland/cursor/object_unique_ptr.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

awl::backends::wayland::cursor::object_unique_ptr
create_invisible(
	awl::backends::wayland::shm const &
);

}
}
}
}

#endif
