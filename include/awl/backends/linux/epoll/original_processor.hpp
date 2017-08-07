#ifndef AWL_BACKENDS_LINUX_EPOLL_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/linux/epoll/set.hpp>
#include <awl/backends/posix/event_container.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace epoll
{

class AWL_DETAIL_CLASS_SYMBOL original_processor
:
	public awl::backends::posix::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor();

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::event::connection_unique_ptr
	register_fd(
		awl::backends::posix::fd const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::posix::event_container
	poll(
		awl::backends::posix::optional_duration const &
	)
	override;
private:
	awl::backends::linux::epoll::set fd_set_;
};

}
}
}
}

#endif
