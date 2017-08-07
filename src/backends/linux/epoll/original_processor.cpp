#include <awl/backends/linux/epoll/original_processor.hpp>
#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/event_container.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/make_connection.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/algorithm/map.hpp>


awl::backends::linux::epoll::original_processor::original_processor()
:
	awl::backends::posix::processor(),
	fd_set_()
{
}

awl::backends::linux::epoll::original_processor::~original_processor()
{
}

awl::event::connection_unique_ptr
awl::backends::linux::epoll::original_processor::register_fd(
	awl::backends::posix::fd const &_fd
)
{
	fd_set_.add(
		_fd
	);

	return
		awl::event::make_connection(
			awl::event::connection_function{
				[
					this,
					_fd
				]{
					fd_set_.remove(
						_fd
					);
				}
			}
		);
}

awl::backends::posix::event_container
awl::backends::linux::epoll::original_processor::poll(
	awl::backends::posix::optional_duration const &_duration
)
{
	return
		fcppt::algorithm::map<
			awl::backends::posix::event_container
		>(
			fd_set_.epoll(
				_duration
			),
			[](
				awl::backends::posix::fd const _fd
			)
			{
				return
					fcppt::make_unique_ptr<
						awl::backends::posix::event
					>(
						_fd
					);
			}
		);
}
