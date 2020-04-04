#include <awl/backends/sdl/cursor/create_invisible.hpp>
#include <awl/backends/sdl/cursor/create_predefined.hpp>
#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/backends/sdl/system/object.hpp>
#include <awl/backends/sdl/system/original_object.hpp>
#include <awl/backends/sdl/system/event/original_processor.hpp>
#include <awl/backends/sdl/visual/flags.hpp>
#include <awl/backends/sdl/visual/object.hpp>
#include <awl/backends/sdl/window/original_object.hpp>
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
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/log/context_reference.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL.h>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::system::original_object::original_object(
	fcppt::log::context_reference
)
:
	awl::backends::sdl::system::object{},
	init_{
		SDL_INIT_TIMER
		|
		SDL_INIT_EVENTS
	},
	event_processor_{
		fcppt::unique_ptr_to_base<
			awl::system::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::sdl::system::event::original_processor
			>()
		)
	}
{
}

awl::backends::sdl::system::original_object::~original_object()
= default;

awl::window::object_unique_ptr
awl::backends::sdl::system::original_object::create_window(
	awl::window::parameters const &_parameters
)
{
	fcppt::cast::dynamic_exn<
		awl::backends::sdl::visual::object const &
	>(
		_parameters.visual()
	).apply();

	return
		fcppt::unique_ptr_to_base<
			awl::window::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::sdl::window::original_object
			>(
				_parameters
			)
		);
}

awl::system::event::processor &
awl::backends::sdl::system::original_object::processor()
{
	return
		*this->event_processor_;
}

awl::visual::object_unique_ptr
awl::backends::sdl::system::original_object::default_visual()
{
	return
		fcppt::unique_ptr_to_base<
			awl::visual::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::sdl::visual::object
			>(
				awl::backends::sdl::visual::flags{
					std::uint32_t{
						0
					}
				}
			)
		);
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
