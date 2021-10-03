#ifndef AWL_BACKENDS_WAYLAND_OPTIONAL_SHELL_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_OPTIONAL_SHELL_FWD_HPP_INCLUDED

#include <awl/backends/wayland/shell_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl::backends::wayland
{

using
optional_shell
=
fcppt::optional::object<
	awl::backends::wayland::shell
>;

}

#endif
