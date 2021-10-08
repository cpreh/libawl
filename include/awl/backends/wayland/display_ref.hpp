#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_REF_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_REF_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <fcppt/reference_impl.hpp>

namespace awl::backends::wayland
{

using display_ref = fcppt::reference<awl::backends::wayland::display>;

}

#endif
