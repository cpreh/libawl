#include <awl/backends/linux/timer/object.hpp>
#include <awl/backends/linux/timerfd/object.hpp>
#include <awl/backends/linux/timerfd/unique_ptr.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/timer.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/timer/setting_fwd.hpp>


awl::backends::linux::timer::object::object(
	awl::backends::linux::timerfd::unique_ptr &&_timer,
	awl::event::connection_unique_ptr &&_connection
)
:
	awl::backends::posix::timer{},
	timer_{
		std::move(
			_timer
		)
	},
	connection_{
		std::move(
			_connection
		)
	}
{
}

awl::backends::linux::timer::object::~object()
{
}

awl::backends::posix::fd
awl::backends::linux::timer::object::fd() const
{
	return
		timer_->get();
}

void
awl::backends::linux::timer::object::set(
	awl::timer::setting const &_setting
)
{
	timer_->set_time(
		_setting
	);
}

void
awl::backends::linux::timer::object::read()
{
	timer_->read();
}
