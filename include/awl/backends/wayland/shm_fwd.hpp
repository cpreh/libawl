#ifndef AWL_BACKENDS_WAYLAND_SHM_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SHM_FWD_HPP_INCLUDED

#include <awl/backends/wayland/make_registry_object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

namespace awl::backends::wayland
{

AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_FWD(shm);

}

#endif
