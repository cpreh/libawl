#ifndef AWL_TIMER_DELAY_HPP_INCLUDED
#define AWL_TIMER_DELAY_HPP_INCLUDED

#include <awl/timer/duration.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep

namespace awl::timer
{

FCPPT_DECLARE_STRONG_TYPEDEF(awl::timer::duration, delay);

}

#endif
