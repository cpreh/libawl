#include <awl/backends/sdl/window/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::window::object::object()
:
	awl::window::object{}
{
}

awl::backends::sdl::window::object::~object()
{
}

void
awl::backends::sdl::window::object::show()
{
	SDL_ShowWindow(
		&this->get()
	);
}

awl::window::dim
awl::backends::sdl::window::object::size() const
{
	int w{0};

	int h{0};

	SDL_GetWindowSize(
		&this->get(),
		&w,
		&h
	);

	return
		awl::window::dim{
			fcppt::cast::to_unsigned(
				w
			),
			fcppt::cast::to_unsigned(
				h
			)
		};
}
