#ifndef AWL_BACKENDS_LINUX_TIMERFD_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMERFD_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/linux/timerfd/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace timerfd
{

typedef
fcppt::unique_ptr<
	awl::backends::linux::timerfd::object
>
unique_ptr;

}
}
}
}

#endif