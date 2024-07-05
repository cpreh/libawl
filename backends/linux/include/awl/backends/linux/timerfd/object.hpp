#ifndef AWL_BACKENDS_LINUX_TIMERFD_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMERFD_OBJECT_HPP_INCLUDED

#include <awl/backends/linux/timerfd/object_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::linux::timerfd
{

class object
{
  FCPPT_NONMOVABLE(object);

public:
  object();

  ~object();

  [[nodiscard]] awl::backends::posix::fd get() const;

  void set_time(awl::timer::setting const &);

  using value_type = std::uint64_t;

  [[nodiscard]] value_type read();

private:
  awl::backends::posix::fd const fd_;
};

}

#endif
