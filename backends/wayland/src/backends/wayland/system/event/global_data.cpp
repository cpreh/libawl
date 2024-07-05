#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/global_data.hpp>
#include <awl/event/base.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/object_reference.hpp>

awl::backends::wayland::system::event::global_data::global_data(
    fcppt::log::object_reference const _log,
    awl::backends::wayland::display_reference const _display)
    : log_{_log},
      display_{_display},
      compositor_{},
      shell_{},
      shm_{},
      seats_{},
      exit_code_{},
      last_events_{}
{
}

awl::backends::wayland::system::event::global_data::~global_data() = default;
