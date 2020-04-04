#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/system/event/push.hpp>
#include <awl/backends/sdl/system/event/timer_type.hpp>
#include <awl/backends/sdl/timer/event_code.hpp>
#include <awl/backends/sdl/timer/object.hpp>
#include <awl/timer/duration.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/to_void_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_stdinc.h>
#include <SDL_timer.h>
#include <chrono>
#include <fcppt/config/external_end.hpp>


namespace
{

Uint32
convert_time(
	awl::timer::duration const _duration
)
{
	return
		fcppt::cast::size<
			Uint32
		>(
			fcppt::cast::to_unsigned(
				std::chrono::duration_cast<
					std::chrono::milliseconds
				>(
					_duration
				).count()
			)
		);
}

}

awl::backends::sdl::timer::object::object(
	awl::timer::setting const &_setting,
	awl::backends::sdl::system::event::timer_type const _event_type
)
:
	awl::timer::object{},
	period_{
		convert_time(
			_setting.period().get()
		)
	},
	event_type_{
		_event_type
	},
	id_{
		SDL_AddTimer(
			convert_time(
				_setting.delay().get()
			),
			&awl::backends::sdl::timer::object::process,
			fcppt::cast::to_void_ptr(
				this
			)
		)
	}
{
	if(
		this->id_
		==
		0
	)
	{
		throw
			awl::backends::sdl::exception{
				FCPPT_TEXT("SDL_AddTimer failed")
			};
	}
}

awl::backends::sdl::timer::object::~object()
{
	SDL_RemoveTimer(
		this->id_
	);
}

Uint32
SDLCALL
awl::backends::sdl::timer::object::process(
	Uint32,
	void *const _data
)
{
	awl::backends::sdl::timer::object &timer{
		*fcppt::cast::from_void_ptr<
			awl::backends::sdl::timer::object *
		>(
			_data
		)
	};

	SDL_Event event;

	event.user =
		SDL_UserEvent{
			timer.event_type_.get().get(),
			SDL_GetTicks(),
			fcppt::literal<
			Uint32
			>(
				0
			),
			awl::backends::sdl::timer::event_code(),
			fcppt::cast::to_void_ptr(
				&timer
			),
			nullptr
		};

	// TODO(philipp): Error handling?
	try
	{
		awl::backends::sdl::system::event::push(
			event
		);
	}
	catch(...)
	{
	}

	return
		timer.period_;
}
