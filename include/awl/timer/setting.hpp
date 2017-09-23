#ifndef AWL_TIMER_SETTING_HPP_INCLUDED
#define AWL_TIMER_SETTING_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/timer/delay.hpp>
#include <awl/timer/period.hpp>
#include <awl/timer/setting_fwd.hpp>


namespace awl
{
namespace timer
{

class setting
{
public:
	AWL_DETAIL_SYMBOL
	setting(
		awl::timer::delay,
		awl::timer::period
	);

	AWL_DETAIL_SYMBOL
	awl::timer::delay
	delay() const;

	AWL_DETAIL_SYMBOL
	awl::timer::period
	period() const;
private:
	awl::timer::delay delay_;

	awl::timer::period period_;
};

}
}

#endif
