#include <awl/backends/sdl/window/object_data_name.hpp>
#include <awl/backends/sdl/window/object_fwd.hpp>
#include <awl/backends/sdl/window/set_data.hpp>
#include <awl/backends/sdl/window/set_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::sdl::window::set_object(
	SDL_Window &_window,
	awl::backends::sdl::window::object &_ref
)
{
	awl::backends::sdl::window::set_data(
		_window,
		awl::backends::sdl::window::object_data_name(),
		&_ref
	);
}
