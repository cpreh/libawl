#include <awl/backends/sdl/system/event/object.hpp>
#include <awl/backends/sdl/system/event/timer_type.hpp>
#include <awl/backends/sdl/system/event/translate.hpp>
#include <awl/backends/sdl/timer/object.hpp>
#include <awl/backends/sdl/window/from_id.hpp>
#include <awl/backends/sdl/window/get_object.hpp>
#include <awl/backends/sdl/window/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/show.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <SDL_video.h>
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
	{
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
	}

	if(
		_event.type
		==
		SDL_WINDOWEVENT
	)
	{
		SDL_WindowEvent const &event{
			_event.window
		};

		fcppt::reference<
			SDL_Window
		> const sdl_window{
			FCPPT_ASSERT_OPTIONAL_ERROR(
				awl::backends::sdl::window::from_id(
					event.windowID
				)
			)
		};

		awl::backends::sdl::window::object &sdl_window_ref{
			awl::backends::sdl::window::get_object(
				sdl_window
			)
		};

		awl::window::reference const window{
			fcppt::reference_to_base<
				awl::window::object
			>(
				fcppt::make_ref(
					sdl_window_ref
				)
			)
		};

		switch(
			event.event
		)
		{
		case SDL_WINDOWEVENT_SHOWN:
			return
				fcppt::optional::make(
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::window::event::show
						>(
							window
						)
					)
				);
		case SDL_WINDOWEVENT_HIDDEN:
			return
				fcppt::optional::make(
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::window::event::hide
						>(
							window
						)
					)
				);
		case SDL_WINDOWEVENT_RESIZED:
			return
				fcppt::optional::make(
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::window::event::resize
						>(
							window,
							awl::window::dim{
								fcppt::cast::to_unsigned(
									event.data1
								),
								fcppt::cast::to_unsigned(
									event.data2
								)
							}
						)
					)
				);
		case SDL_WINDOWEVENT_CLOSE:
			return
				fcppt::optional::make(
					fcppt::unique_ptr_to_base<
						awl::event::base
					>(
						fcppt::make_unique_ptr<
							awl::window::event::close
						>(
							window
						)
					)
				);
		case SDL_WINDOWEVENT_ENTER:
			sdl_window_ref.set_cursor();
			break;

		// TODO(philipp): Add destroy event
		}
	}

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
