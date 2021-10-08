#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_FD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_FD_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::wayland
{

AWL_DETAIL_SYMBOL
awl::backends::posix::fd display_fd(awl::backends::wayland::display const &);

}

#endif
