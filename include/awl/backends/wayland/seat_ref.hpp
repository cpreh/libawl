#ifndef AWL_BACKENDS_WAYLAND_SEAT_REF_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SEAT_REF_HPP_INCLUDED

#include <awl/backends/wayland/seat_fwd.hpp>
#include <fcppt/reference_impl.hpp>

namespace awl::backends::wayland
{

using seat_ref = fcppt::reference<awl::backends::wayland::seat>;

}

#endif
