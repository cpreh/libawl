#ifndef AWL_BACKENDS_LINUX_EPOLL_FD_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_FD_HPP_INCLUDED

#include <awl/backends/linux/epoll/fd_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::linux::epoll
{

class fd
{
	FCPPT_NONMOVABLE(
		fd
	);
public:
	AWL_DETAIL_SYMBOL
	fd();

	AWL_DETAIL_SYMBOL
	~fd();

	[[nodiscard]]
	awl::backends::posix::fd
	get() const;
private:
	awl::backends::posix::fd const fd_;
};

}

#endif
