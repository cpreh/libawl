#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/system/event/push.hpp>
#include <awl/backends/sdl/system/event/timer_type.hpp>
#include <awl/backends/sdl/timer/event_code.hpp>
#include <awl/backends/sdl/timer/object.hpp>
#include <awl/timer/duration.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/to_void_ptr.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/object_reference.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_stdinc.h>
#include <SDL_timer.h>
#include <chrono>
#include <exception>
#include <string>
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
	fcppt::log::object_reference const _log,
	awl::timer::setting const &_setting,
	awl::backends::sdl::system::event::timer_type const _event_type
)
:
	awl::timer::object{},
	log_{
		_log
	},
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

	fcppt::log::object &log{
		timer.log_.get()
	};

	try
	{
		fcppt::either::match(
			awl::backends::sdl::system::event::push(
				event
			),
			[
				&log
			](
				fcppt::optional::object<
					std::string
				> const &_error
			)
			{
				FCPPT_LOG_ERROR(
					log,
					fcppt::log::out
						<<
						FCPPT_TEXT("Failed to push timer event.")
				)

				fcppt::optional::maybe_void(
					_error,
					[
						&log
					](
						std::string const &_text
					)
					{
						FCPPT_LOG_ERROR(
							log,
							fcppt::log::out
								<<
								fcppt::from_std_string(
									_text
								)
						)
					}
				);
			},
			[](
				fcppt::either::no_error
			)
			{
			}
		);
	}
	catch(
		fcppt::exception const &_error
	)
	{
		FCPPT_LOG_ERROR(
			log,
			fcppt::log::out
			<<
			FCPPT_TEXT("Caught exception in timer event: ")
			<<
			_error.string()
		)
	}
	catch(
		std::exception const &_error
	)
	{
		FCPPT_LOG_ERROR(
			log,
			fcppt::log::out
			<<
			FCPPT_TEXT("Caught exception in timer event: ")
			<<
			fcppt::from_std_string(
				_error.what()
			)
		)
	}
	catch(...)
	{
		FCPPT_LOG_ERROR(
			log,
			fcppt::log::out
			<<
			FCPPT_TEXT("Caught unknown exception in timer event.")
		)
	}

	return
		timer.period_;
}
