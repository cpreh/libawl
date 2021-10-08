#ifndef AWL_BACKENDS_LINUX_EPOLL_FD_VECTOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_FD_VECTOR_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::linux::epoll
{

using fd_vector = std::vector<awl::backends::posix::fd>;

}

#endif
