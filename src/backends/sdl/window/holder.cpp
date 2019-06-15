#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/window/holder.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::window::holder::holder(
	SDL_Window *const _window
)
:
	window_{
		_window
	}
{
	if(
		this->window_
		==
		nullptr
	)
		throw
			awl::backends::sdl::exception{
				FCPPT_TEXT("SDL_CreateWindow failed")
			};
}

awl::backends::sdl::window::holder::~holder()
{
	SDL_DestroyWindow(
		this->window_
	);
}

SDL_Window *
awl::backends::sdl::window::holder::get() const
{
	return
		this->window_;
}
