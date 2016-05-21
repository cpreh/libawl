#include <awl/exception.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/linux/epoll/fd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


awl::backends::linux::epoll::fd::fd()
:
	fd_{
		::epoll_create(
			1 // some hint for the number of fds
		)
	}
{
	if(
		fd_.get()
		==
		-1
	)
		throw
			awl::exception{
				FCPPT_TEXT("epoll_create failed!")
			};
}

awl::backends::linux::epoll::fd::~fd()
{
	::close(
		fd_.get()
	);
}

awl::backends::posix::fd
awl::backends::linux::epoll::fd::get() const
{
	return
		fd_;
}
