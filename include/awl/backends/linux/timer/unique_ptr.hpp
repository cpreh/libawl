#ifndef AWL_BACKENDS_LINUX_TIMER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/linux/timer/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace timer
{

typedef
fcppt::unique_ptr<
	awl::backends::linux::timer::object
>
unique_ptr;

}
}
}
}

#endif
