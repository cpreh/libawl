#ifndef AWL_BACKENDS_WAYLAND_OPTIONAL_SHM_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_OPTIONAL_SHM_FWD_HPP_INCLUDED

#include <awl/backends/wayland/shm_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>

namespace awl::backends::wayland
{

using optional_shm = fcppt::optional::object<awl::backends::wayland::shm>;

}

#endif
