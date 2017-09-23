#include <awl/timer/delay.hpp>
#include <awl/timer/period.hpp>
#include <awl/timer/setting.hpp>


awl::timer::setting::setting(
	awl::timer::delay const _delay,
	awl::timer::period const _period
)
:
	delay_{
		_delay
	},
	period_{
		_period
	}
{
}

awl::timer::delay
awl::timer::setting::delay() const
{
	return
		delay_;
}

awl::timer::period
awl::timer::setting::period() const
{
	return
		period_;
}
