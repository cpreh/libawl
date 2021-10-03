#ifndef AWL_BACKENDS_SDL_TIMER_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_TIMER_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/system/event/timer_type.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/log/object_reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_stdinc.h>
#include <SDL_timer.h>
#include <fcppt/config/external_end.hpp>


namespace awl::backends::sdl::timer
{

class object
:
	public awl::timer::object
{
	FCPPT_NONMOVABLE(
		object
	);
public:
	object(
		fcppt::log::object_reference,
		awl::timer::setting const &,
		awl::backends::sdl::system::event::timer_type
	);

	~object()
	override;
private:
	static
	Uint32
	SDLCALL
	process(
		Uint32,
		void *
	);

	fcppt::log::object_reference const log_;

	Uint32 const period_;

	awl::backends::sdl::system::event::timer_type const event_type_;

	SDL_TimerID const id_;
};

}

#endif
