#include <awl/backends/sdl/get_error.hpp>
#include <awl/backends/sdl/system/event/push.hpp>
#include <fcppt/const.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::either::error<
	fcppt::optional::object<
		std::string
	>
>
awl::backends::sdl::system::event::push(
	SDL_Event const &_event
)
{
	SDL_Event event{
		_event
	};

	return
		fcppt::either::construct(
			SDL_PushEvent(
				&event
			)
			!=
			-1,
			fcppt::const_(
				fcppt::either::no_error{}
			),
			[]{
				return
					awl::backends::sdl::get_error();
			}
		);
}
