#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/pending.hpp>
#include <fcppt/cast/to_unsigned.hpp>

unsigned awl::backends::x11::pending(awl::backends::x11::display const &_display)
{
  return fcppt::cast::to_unsigned(::XEventsQueued(_display.get(), QueuedAlready));
}
