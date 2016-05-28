#ifndef AWL_BACKENDS_POSIX_TIMER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_TIMER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/posix/timer_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

typedef
fcppt::unique_ptr<
	awl::backends::posix::timer
>
timer_unique_ptr;

}
}
}

#endif
