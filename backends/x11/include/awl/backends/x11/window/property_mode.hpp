#ifndef AWL_BACKENDS_X11_WINDOW_PROPERTY_MODE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_PROPERTY_MODE_HPP_INCLUDED

#include <awl/backends/x11/window/property_mode_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::x11::window
{

enum class property_mode : std::uint8_t
{
  replace,
  prepend,
  append
};

}

#endif
