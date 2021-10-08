#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_READ_EVENTS_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_READ_EVENTS_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::wayland
{

AWL_DETAIL_SYMBOL
void display_read_events(awl::backends::wayland::display const &);

}

#endif
