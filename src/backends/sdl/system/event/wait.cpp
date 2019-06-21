#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/system/event/wait.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


SDL_Event
awl::backends::sdl::system::event::wait()
{
	SDL_Event result;

	if(
		SDL_WaitEvent(
			&result
		)
		!=
		0
	)
		throw
			awl::backends::sdl::exception{
				FCPPT_TEXT("SDL_WaitEvent failed!")
			};

	return
		result;
}
