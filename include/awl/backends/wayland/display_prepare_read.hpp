#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_PREPARE_READ_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_PREPARE_READ_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::wayland
{

[[nodiscard]]
AWL_DETAIL_SYMBOL
bool
display_prepare_read(
	awl::backends::wayland::display const &
)
noexcept(true);

}

#endif
