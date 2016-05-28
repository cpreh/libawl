#ifndef AWL_BACKENDS_POSIX_TIMER_DELAY_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_TIMER_DELAY_HPP_INCLUDED

#include <awl/backends/posix/duration.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

FCPPT_MAKE_STRONG_TYPEDEF(
	awl::backends::posix::duration,
	timer_delay
);

}
}
}

#endif
