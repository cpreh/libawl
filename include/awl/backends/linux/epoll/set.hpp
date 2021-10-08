#ifndef AWL_BACKENDS_LINUX_EPOLL_SET_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_SET_HPP_INCLUDED

#include <awl/backends/linux/epoll/fd.hpp>
#include <awl/backends/linux/epoll/fd_vector.hpp>
#include <awl/backends/linux/epoll/set_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::linux::epoll
{

class set
{
  FCPPT_NONMOVABLE(set);

public:
  AWL_DETAIL_SYMBOL
  set();

  AWL_DETAIL_SYMBOL
  ~set();

  AWL_DETAIL_SYMBOL
  void add(awl::backends::posix::fd);

  AWL_DETAIL_SYMBOL
  void remove(awl::backends::posix::fd);

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::backends::linux::epoll::fd_vector
  epoll(awl::backends::posix::optional_duration const &);

private:
  awl::backends::linux::epoll::fd const epoll_fd_;

  using event_vector = std::vector<epoll_event>;

  event_vector events_;
};

}

#endif
