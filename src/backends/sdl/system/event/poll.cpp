#include <awl/backends/sdl/system/event/poll.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	SDL_Event
>
awl::backends::sdl::system::event::poll()
{
	SDL_Event result;

	return
		fcppt::optional::make_if(
			SDL_PollEvent(
				&result
			)
			==
			1,
			[
				&result
			]{
				return
					result;
			}
		);
}
