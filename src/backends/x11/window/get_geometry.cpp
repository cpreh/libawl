#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/get_geometry.hpp>
#include <awl/backends/x11/window/rect.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::window::rect
awl::backends::x11::window::get_geometry(awl::backends::x11::window::base const &_window)
{
  Window root_return{};

  int x_return{0};
  int y_return{0};

  unsigned width_return{0};
  unsigned height_return{0};
  unsigned border_width_return{0};
  unsigned depth_return{0};

  if (::XGetGeometry(
          _window.display().get().get(),
          _window.get(),
          &root_return,
          &x_return,
          &y_return,
          &width_return,
          &height_return,
          &border_width_return,
          &depth_return) == 0)
  {
    throw awl::exception{FCPPT_TEXT("XGetGeometry() failed!")};
  }

  return awl::backends::x11::window::rect{
      awl::backends::x11::window::rect::vector{x_return, y_return},
      awl::backends::x11::window::rect::dim{
          fcppt::cast::to_signed(width_return), fcppt::cast::to_signed(height_return)}};
}
