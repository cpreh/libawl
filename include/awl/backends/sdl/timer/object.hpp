#ifndef AWL_BACKENDS_SDL_TIMER_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_TIMER_OBJECT_HPP_INCLUDED

#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_timer.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace timer
{

class object
:
	public awl::timer::object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	explicit
	object(
		awl::timer::setting const &
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

	Uint32 const period_;

	SDL_TimerID const id_;
};

}
}
}
}

#endif
