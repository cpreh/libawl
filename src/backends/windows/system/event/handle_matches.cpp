#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_matches.hpp>
#include <awl/backends/windows/system/event/handle_ready.hpp>
#include <awl/event/base.hpp>
#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/optional/maybe.hpp>

bool awl::backends::windows::system::event::handle_matches(
    awl::event::base const &_event, awl::backends::windows::system::event::handle const &_handle)
{
  return fcppt::optional::maybe(
      fcppt::cast::dynamic<awl::backends::windows::system::event::handle_ready const>(_event),
      fcppt::const_(false),
      [&_handle](
          fcppt::reference<awl::backends::windows::system::event::handle_ready const> const _ready)
      { return _ready.get().get() == _handle.get(); });
}
