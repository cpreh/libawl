#include <awl/event/base.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/match.hpp>
#include <awl/timer/object_fwd.hpp>
#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/optional/maybe.hpp>


bool
awl::timer::match(
	awl::event::base const &_event,
	awl::timer::object const &_timer
)
{
	return
		fcppt::optional::maybe(
			fcppt::cast::dynamic<
				awl::timer::event const
			>(
				_event
			),
			fcppt::const_(
				false
			),
			[
				&_timer
			](
				fcppt::reference<
					awl::timer::event const
				> const _timer_event
			)
			{
				return
					&_timer_event.get().get()
					==
					&_timer;
			}
		);

}
