#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/delete_property.hpp>
#include <awl/backends/x11/window/property.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

void awl::backends::x11::window::delete_property(
    awl::backends::x11::window::base const &_window,
    awl::backends::x11::window::property const _property)
{
  // Always returns 1
  XDeleteProperty(_window.display().get().get(), _window.get(), _property.get().get());
}
