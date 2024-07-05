#include <awl/backends/windows/timer/object.hpp>
#include <awl/backends/windows/timer/waitable.hpp>
#include <awl/backends/windows/timer/waitable_unique_ptr.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

awl::backends::windows::timer::object::object(
    awl::timer::setting const &_setting,
    awl::backends::windows::timer::waitable_unique_ptr &&_timer,
    awl::event::connection_unique_ptr &&_connection)
    : awl::timer::object{}, timer_{std::move(_timer)}, connection_{std::move(_connection)}
{
  timer_->set(_setting);
}

awl::backends::windows::timer::object::~object() {}
