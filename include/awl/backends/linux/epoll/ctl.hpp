#ifndef AWL_BACKENDS_LINUX_EPOLL_CTL_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_CTL_HPP_INCLUDED

#include <awl/backends/linux/epoll/fd_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace epoll
{

AWL_DETAIL_SYMBOL
void
ctl(
	awl::backends::linux::epoll::fd const &,
	int,
	awl::backends::posix::fd const &,
	epoll_event *
);

}
}
}
}

#endif
