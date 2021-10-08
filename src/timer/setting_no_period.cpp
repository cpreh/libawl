#include <awl/timer/delay.hpp>
#include <awl/timer/duration.hpp>
#include <awl/timer/period.hpp>
#include <awl/timer/setting.hpp>
#include <awl/timer/setting_no_period.hpp>

awl::timer::setting awl::timer::setting_no_period(awl::timer::delay const _delay)
{
  return awl::timer::setting{
      _delay,
      awl::timer::period{// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
                         awl::timer::duration{0}}};
}
