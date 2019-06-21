#include <awl/backends/sdl/system/event/object.hpp>
#include <awl/event/base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::system::event::object::object(
	SDL_Event const &_event
)
:
	awl::event::base{},
	event_{
		_event
	}
{
}

awl::backends::sdl::system::event::object::~object()
{
}

SDL_Event const &
awl::backends::sdl::system::event::object::get() const
{
	return
		this->event_;
}
