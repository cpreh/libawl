#ifndef AWL_TIMER_SETTING_NO_PERIOD_HPP_INCLUDED
#define AWL_TIMER_SETTING_NO_PERIOD_HPP_INCLUDED

#include <awl/timer/delay.hpp>
#include <awl/timer/setting.hpp>

namespace awl::timer
{

AWL_DETAIL_SYMBOL
awl::timer::setting setting_no_period(awl::timer::delay);

}

#endif
