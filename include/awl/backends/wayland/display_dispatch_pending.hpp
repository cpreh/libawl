#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_DISPATCH_PENDING_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_DISPATCH_PENDING_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::wayland
{

AWL_DETAIL_SYMBOL
void
display_dispatch_pending(
	awl::backends::wayland::display const &
);

}

#endif
