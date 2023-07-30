#include <awl/exception.hpp>
#include <awl/backends/linux/epoll/ctl.hpp>
#include <awl/backends/linux/epoll/fd_vector.hpp>
#include <awl/backends/linux/epoll/set.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <chrono>
#include <fcppt/config/external_end.hpp>

awl::backends::linux::epoll::set::set() : epoll_fd_{}, events_{} {}

awl::backends::linux::epoll::set::~set() = default;

void awl::backends::linux::epoll::set::add(awl::backends::posix::fd const _fd)
{
  // NOLINTNEXTLINE(hicpp-use-emplace,modernize-use-emplace)
  this->events_.push_back(epoll_event{});

  epoll_event ev{};
  ev.events = EPOLLIN;
  ev.data.fd = _fd.get();

  awl::backends::linux::epoll::ctl(this->epoll_fd_, EPOLL_CTL_ADD, _fd, &ev);
}

void awl::backends::linux::epoll::set::remove(awl::backends::posix::fd const _fd)
{
  awl::backends::linux::epoll::ctl(this->epoll_fd_, EPOLL_CTL_DEL, _fd, nullptr);

  this->events_.pop_back();
}

awl::backends::linux::epoll::fd_vector awl::backends::linux::epoll::set::epoll(
    awl::backends::posix::optional_duration const &_opt_duration)
{
  int const ret{::epoll_wait(
      this->epoll_fd_.get().get(),
      this->events_.data(),
      fcppt::cast::size<int>(fcppt::cast::to_signed(this->events_.size())),
      fcppt::optional::maybe(
          _opt_duration,
          fcppt::const_(-1),
          [](awl::backends::posix::duration const _duration)
          {
            return fcppt::optional::to_exception(
                fcppt::cast::truncation_check<int>(
                    std::chrono::duration_cast<std::chrono::milliseconds>(_duration).count()),
                [_duration]
                {
                  return awl::exception{
                      FCPPT_TEXT("Duration value ") +
                      fcppt::output_to_fcppt_string(_duration.count()) +
                      FCPPT_TEXT(" is too large for epoll_wait")};
                });
          }))};

  if (ret == -1)
  {
    throw awl::exception{FCPPT_TEXT("epoll_wait failed!")};
  }

  unsigned const ready{fcppt::cast::to_unsigned(ret)};

  return fcppt::algorithm::map_optional<awl::backends::linux::epoll::fd_vector>(
      fcppt::make_int_range_count(ready),
      [this](unsigned const _index)
      {
        epoll_event const &event{this->events_[_index]};

        return fcppt::optional::make_if(
            (event.events & EPOLLIN) != 0,
            [&event] { return awl::backends::posix::fd{event.data.fd}; });
      });
}
