#include <awl/backends/sdl/system/event/object.hpp>
#include <awl/backends/sdl/system/event/timer_type.hpp>
#include <awl/backends/sdl/system/event/translate.hpp>
#include <awl/backends/sdl/timer/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/object.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


namespace
{

fcppt::optional::object<
	awl::event::base_unique_ptr
>
translate_opt(
	awl::backends::sdl::system::event::timer_type const _timer_event,
	SDL_Event const &_event
)
{
	if(
		_event.type
		==
		_timer_event.get().get()
	)
		return
			fcppt::optional::make(
				fcppt::unique_ptr_to_base<
					awl::event::base
				>(
					fcppt::make_unique_ptr<
						awl::timer::event
					>(
						fcppt::reference_to_base<
							awl::timer::object
						>(
							fcppt::make_ref(
								*fcppt::cast::from_void_ptr<
									awl::backends::sdl::timer::object *
								>(
									_event.user.data1
								)
							)
						)
					)
				)
			);

	// TODO
	return
		fcppt::optional::object<
			awl::event::base_unique_ptr
		>{};
}

}

awl::event::base_unique_ptr
awl::backends::sdl::system::event::translate(
	awl::backends::sdl::system::event::timer_type const _timer_event,
	SDL_Event const &_event
)
{
	return
		fcppt::optional::from(
			translate_opt(
				_timer_event,
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
