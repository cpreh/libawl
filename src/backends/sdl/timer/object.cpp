#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/timer/events.hpp>
#include <awl/backends/sdl/timer/object.hpp>
#include <awl/event/base.hpp>
#include <awl/timer/duration.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/to_void_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_timer.h>
#include <atomic>
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
	fcppt::reference<
		awl::backends::sdl::timer::events
	> const _events,
	awl::timer::setting const &_setting
)
:
	awl::timer::object{},
	events_{
		_events
	},
	period_{
		convert_time(
			_setting.period().get()
		)
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
		throw
			awl::backends::sdl::exception{
				FCPPT_TEXT("SDL_AddTimer failed")
			};
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

	timer.events_.get().push_back(
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
						timer
					)
				)
			)
		)
	);

	return
		timer.period_;
}
