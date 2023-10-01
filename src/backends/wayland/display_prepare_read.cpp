#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_prepare_read.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>

bool awl::backends::wayland::display_prepare_read(
    awl::backends::wayland::display const &_display) noexcept(true)
{
  return ::wl_display_prepare_read(_display.get()) == 0;
}
