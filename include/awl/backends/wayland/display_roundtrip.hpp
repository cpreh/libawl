#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_ROUNDTRIP_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_ROUNDTRIP_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::wayland
{

AWL_DETAIL_SYMBOL
void
display_roundtrip(
	awl::backends::wayland::display const &
);

}

#endif
