#include <awl/exception.hpp>
#include <awl/backends/linux/epoll/ctl.hpp>
#include <awl/backends/linux/epoll/fd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::linux::epoll::ctl(
	awl::backends::linux::epoll::fd const &_epoll_fd,
	awl::backends::posix::fd const &_fd,
	epoll_event *const _data
)
{

	if(
		_data != nullptr
	)
	{
		_data->events = EPOLLIN;

		_data->data.fd = _fd.get();
	}

	if(
		::epoll_ctl(
			_epoll_fd.get().get(),
			_data
			?
				EPOLL_CTL_ADD
			:
				EPOLL_CTL_DEL
			,
			_fd.get(),
			_data
		)
		!= 0
	)
		throw
			awl::exception{
				FCPPT_TEXT("epoll_ctl failed!")
			};
}
