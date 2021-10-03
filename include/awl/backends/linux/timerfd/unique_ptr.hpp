#ifndef AWL_BACKENDS_LINUX_TIMERFD_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMERFD_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/linux/timerfd/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl::backends::linux::timerfd
{

using
unique_ptr
=
fcppt::unique_ptr<
	awl::backends::linux::timerfd::object
>;

}

#endif
