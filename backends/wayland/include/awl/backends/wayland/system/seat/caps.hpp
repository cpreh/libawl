#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_CAPS_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps_fwd.hpp> // IWYU pragma: keep
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::wayland::system::seat
{

enum class caps : std::uint8_t
{
  pointer,
  keyboard
};

}

FCPPT_ENUM_DEFINE_MAX_VALUE(awl::backends::wayland::system::seat::caps::keyboard);

#endif
