#ifndef AWL_TIMER_SETTING_NO_DELAY_HPP_INCLUDED
#define AWL_TIMER_SETTING_NO_DELAY_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/timer/period.hpp>
#include <awl/timer/setting.hpp>

namespace awl::timer
{

AWL_DETAIL_SYMBOL
awl::timer::setting setting_no_delay(awl::timer::period);

}

#endif
