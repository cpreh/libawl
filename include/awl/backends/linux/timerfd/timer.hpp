#ifndef AWL_BACKENDS_LINUX_TIMERFD_TIMER_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMERFD_TIMER_HPP_INCLUDED

#include <awl/backends/linux/timerfd/object.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/timer.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/backends/posix/timer_delay.hpp>
#include <awl/backends/posix/timer_period.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace timerfd
{

class timer
:
	public awl::backends::posix::timer
{
	FCPPT_NONCOPYABLE(
		timer
	);
public:
	AWL_DETAIL_SYMBOL
	timer(
		awl::backends::posix::processor &,
		awl::backends::posix::callback const &,
		awl::backends::posix::timer_delay,
		awl::backends::posix::timer_period
	);

	AWL_DETAIL_SYMBOL
	~timer()
	override;
private:
	awl::backends::linux::timerfd::object fd_;

	fcppt::signal::auto_connection const fd_connection_;
};

}
}
}
}

#endif
