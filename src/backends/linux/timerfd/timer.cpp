#include <awl/backends/linux/timerfd/object.hpp>
#include <awl/backends/linux/timerfd/timer.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/event_fwd.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/posix/timer.hpp>
#include <awl/backends/posix/timer_delay.hpp>
#include <awl/backends/posix/timer_period.hpp>
#include <fcppt/algorithm/repeat.hpp>


awl::backends::linux::timerfd::timer::timer(
	awl::backends::posix::processor &_processor,
	awl::backends::posix::callback const &_callback,
	awl::backends::posix::timer_delay const _delay,
	awl::backends::posix::timer_period const _period
)
:
	awl::backends::posix::timer(),
	fd_{},
	fd_connection_{
		_processor.register_fd_callback(
			fd_.get(),
			awl::backends::posix::callback{
				[
					this,
					_callback
				](
					awl::backends::posix::event const &_event
				)
				{
					fcppt::algorithm::repeat(
						fd_.read(),
						[
							&_callback,
							&_event
						]{
							_callback(
								_event
							);
						}
					);
				}
			}
		)
	}
{
	fd_.set_time(
		_delay,
		_period
	);
}

awl::backends::linux::timerfd::timer::~timer()
{
}
