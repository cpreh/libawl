#include <awl/backends/posix/fd.hpp>
#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlibint.h> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_end.hpp>

awl::backends::posix::fd
awl::backends::x11::display_fd(awl::backends::x11::display_ref const _display)
{
  return awl::backends::posix::fd{_display.get().get()->fd};
}
