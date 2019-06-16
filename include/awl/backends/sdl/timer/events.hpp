#ifndef AWL_BACKENDS_SDL_TIMER_EVENTS_HPP_INCLUDED
#define AWL_BACKENDS_SDL_TIMER_EVENTS_HPP_INCLUDED

#include <awl/backends/sdl/timer/events_fwd.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace timer
{

class events
{
	FCPPT_NONCOPYABLE(
		events
	);
public:
	events();

	~events();

	void
	push_back(
		awl::event::base_unique_ptr &&
	);

	awl::event::container
	get();
private:
	awl::event::container events_;
};

}
}
}
}

#endif
