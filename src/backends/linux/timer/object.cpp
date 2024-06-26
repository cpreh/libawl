#include <awl/backends/linux/timer/object.hpp>
#include <awl/backends/linux/timerfd/object.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/linux/timerfd/unique_ptr.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/timer.hpp>
#include <awl/event/connection.hpp> // NOLINT(misc-include-cleaner)
#include <awl/event/connection_unique_ptr.hpp>
#include <fcppt/use.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

awl::backends::linux::timer::object::object(
    awl::backends::linux::timerfd::unique_ptr &&_timer,
    awl::event::connection_unique_ptr &&_connection)
    : awl::backends::posix::timer{}, timer_{std::move(_timer)}, connection_{std::move(_connection)}
{
}

awl::backends::linux::timer::object::~object() = default;

awl::backends::posix::fd awl::backends::linux::timer::object::fd() const { return timer_->get(); }

void awl::backends::linux::timer::object::read()
{
  auto const result{timer_->read()};

  FCPPT_USE(result);
}
