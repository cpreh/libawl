#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/base_unique_ptr.hpp>
#include <awl/backends/x11/window/root.hpp>
#include <awl/backends/x11/window/wrapped.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::window::base_unique_ptr awl::backends::x11::window::root(
    awl::backends::x11::display_ref const _display, awl::backends::x11::screen const _screen)
{
  return fcppt::unique_ptr_to_base<awl::backends::x11::window::base>(
      fcppt::make_unique_ptr<awl::backends::x11::window::wrapped>(
          _display, _screen, ::XRootWindow(_display.get().get(), _screen.get())));
}
