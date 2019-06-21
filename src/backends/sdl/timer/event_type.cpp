#include <awl/backends/sdl/timer/event_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


std::uint32_t
awl::backends::sdl::timer::event_type()
{
	// TODO
	return
		SDL_USEREVENT;
}
