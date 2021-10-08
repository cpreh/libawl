#ifndef AWL_BACKENDS_LINUX_TIMER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/linux/timer/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl::backends::linux::timer
{

using unique_ptr = fcppt::unique_ptr<awl::backends::linux::timer::object>;

}

#endif
