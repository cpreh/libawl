#include <awl/backends/sdl/window/get_data.hpp>
#include <fcppt/const.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	void *
>
awl::backends::sdl::window::get_data(
	SDL_Window &_window,
	std::string const &_name
)
{
	void *const result{
		SDL_GetWindowData(
			&_window,
			_name.c_str()
		)
	};

	return
		fcppt::optional::make_if(
			result
			!=
			nullptr,
			fcppt::const_(
				result
			)
		);
}
