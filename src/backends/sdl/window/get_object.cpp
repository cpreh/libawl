#include <awl/backends/sdl/window/get_data.hpp>
#include <awl/backends/sdl/window/get_object.hpp>
#include <awl/backends/sdl/window/object_data_name.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/reference.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>


awl::window::reference
awl::backends::sdl::window::get_object(
	SDL_Window &_window
)
{
	return
		fcppt::make_ref(
			*fcppt::cast::from_void_ptr<
				awl::window::object *
			>(
				FCPPT_ASSERT_OPTIONAL_ERROR(
					awl::backends::sdl::window::get_data(
						_window,
						awl::backends::sdl::window::object_data_name()
					)
				)
			)
		);
}
