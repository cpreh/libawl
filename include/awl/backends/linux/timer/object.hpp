#ifndef AWL_BACKENDS_LINUX_TIMER_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMER_OBJECT_HPP_INCLUDED

#include <awl/backends/linux/timer/object_fwd.hpp>
#include <awl/backends/linux/timerfd/unique_ptr.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/timer.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::linux::timer
{

class object
:
	public awl::backends::posix::timer
{
	FCPPT_NONMOVABLE(
		object
	);
public:
	AWL_DETAIL_SYMBOL
	object(
		awl::backends::linux::timerfd::unique_ptr &&,
		awl::event::connection_unique_ptr &&
	);

	AWL_DETAIL_SYMBOL
	~object()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::posix::fd
	fd() const
	override;

	AWL_DETAIL_SYMBOL
	void
	read();
private:
	awl::backends::linux::timerfd::unique_ptr const timer_;

	awl::event::connection_unique_ptr const connection_;
};

}

#endif
