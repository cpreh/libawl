#include <awl/backends/sdl/cursor/create_invisible.hpp>
#include <awl/backends/sdl/cursor/create_predefined.hpp>
#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/backends/sdl/system/object.hpp>
#include <awl/backends/sdl/system/original_object.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type.hpp>
#include <awl/cursor/type.hpp>
#include <awl/system/object.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL.h>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::system::original_object::original_object()
:
	awl::backends::sdl::system::object{},
	init_{
		SDL_INIT_TIMER
		|
		SDL_INIT_EVENTS
	}
{
}

awl::backends::sdl::system::original_object::~original_object()
{
}

awl::window::object_unique_ptr
awl::backends::sdl::system::original_object::create_window(
	awl::window::parameters const &_parameters
)
{
}

awl::system::event::processor &
awl::backends::sdl::system::original_object::processor()
{
}

awl::visual::object_unique_ptr
awl::backends::sdl::system::original_object::default_visual()
{
}

awl::cursor::object_unique_ptr
awl::backends::sdl::system::original_object::create_cursor(
	awl::cursor::optional_type const &_optional_type
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::cursor::object
		>(
			fcppt::optional::maybe(
				_optional_type,
				[]{
					return
						awl::backends::sdl::cursor::create_invisible();
				},
				[](
					awl::cursor::type const _type
				)
				{
					return
						awl::backends::sdl::cursor::create_predefined(
							_type
						);
				}
			)
		);
}
