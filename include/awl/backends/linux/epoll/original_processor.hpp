#ifndef AWL_BACKENDS_LINUX_EPOLL_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/linux/epoll/set.hpp>
#include <awl/backends/linux/timer/reference.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/strong_typedef_std_hash.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::linux::epoll
{

class AWL_DETAIL_CLASS_SYMBOL original_processor : public awl::backends::posix::processor
{
  FCPPT_NONMOVABLE(original_processor);

public:
  AWL_DETAIL_SYMBOL
  original_processor();

  AWL_DETAIL_SYMBOL
  ~original_processor() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::event::connection_unique_ptr
  register_fd(awl::backends::posix::fd const &) override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::event::container
  poll(awl::backends::posix::optional_duration const &) override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::timer::unique_ptr
  create_timer(awl::timer::setting const &) override;

private:
  awl::backends::linux::epoll::set fd_set_;

  using timer_map =
      std::unordered_map<awl::backends::posix::fd, awl::backends::linux::timer::reference>;

  timer_map timers_;
};

}

#endif
