#include <awl/backends/sdl/system/event/object.hpp>
#include <awl/backends/sdl/system/event/translate.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


namespace
{

fcppt::optional::object<
	awl::event::base_unique_ptr
>
translate_opt(
	SDL_Event const &_event
)
{
	// TODO
	return
		fcppt::optional::object<
			awl::event::base_unique_ptr
		>{};
}

}

awl::event::base_unique_ptr
awl::backends::sdl::system::event::translate(
	SDL_Event const &_event
)
{
	return
		fcppt::optional::from(
			translate_opt(
				_event
			),
			[
				&_event
			]{
				return
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::backends::sdl::system::event::object
						>(
							_event
						)
					);
			}
		);
}
