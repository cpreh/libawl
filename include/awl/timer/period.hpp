#ifndef AWL_TIMER_PERIOD_HPP_INCLUDED
#define AWL_TIMER_PERIOD_HPP_INCLUDED

#include <awl/timer/duration.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>

namespace awl::timer
{

FCPPT_DECLARE_STRONG_TYPEDEF(awl::timer::duration, period);

}

#endif
