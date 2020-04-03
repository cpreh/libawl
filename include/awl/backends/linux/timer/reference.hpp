#ifndef AWL_BACKENDS_LINUX_TIMER_REFERENCE_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMER_REFERENCE_HPP_INCLUDED

#include <awl/backends/linux/timer/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace timer
{

using
reference
=
fcppt::reference<
	awl::backends::linux::timer::object
>;

}
}
}
}

#endif
