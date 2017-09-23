#ifndef AWL_TIMER_DELAY_HPP_INCLUDED
#define AWL_TIMER_DELAY_HPP_INCLUDED

#include <awl/timer/duration.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace timer
{

FCPPT_MAKE_STRONG_TYPEDEF(
	awl::timer::duration,
	delay
);

}
}

#endif
