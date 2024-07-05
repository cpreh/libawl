#include <awl/config.hpp>
#include <awl/backends/posix/create_processor.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/posix/processor_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#if defined(AWL_LINUX_BACKEND)
#include <awl/backends/linux/epoll/original_processor.hpp>
#endif

awl::backends::posix::processor_unique_ptr awl::backends::posix::create_processor()
{
#if defined(AWL_LINUX_BACKEND)
  return fcppt::unique_ptr_to_base<awl::backends::posix::processor>(
      fcppt::make_unique_ptr<awl::backends::linux::epoll::original_processor>());
#else
#error "Don't know how to make posix processors"
#endif
}
