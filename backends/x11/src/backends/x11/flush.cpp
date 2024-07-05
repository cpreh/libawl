#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/flush.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

void awl::backends::x11::flush(awl::backends::x11::display const &_display)
{
  ::XFlush(_display.get());
}
