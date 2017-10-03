#include <awl/timer/delay.hpp>
#include <awl/timer/period.hpp>
#include <awl/timer/setting.hpp>
#include <awl/timer/setting_no_delay.hpp>


awl::timer::setting
awl::timer::setting_no_delay(
	awl::timer::period const _period
)
{
	return
		awl::timer::setting{
			awl::timer::delay{
				_period.get()
			},
			_period
		};
}
