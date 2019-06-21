#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/system/event/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::event::base
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	object(
		SDL_Event const &
	);

	AWL_DETAIL_SYMBOL
	~object();

	AWL_DETAIL_SYMBOL
	SDL_Event const &
	get() const;
private:
	SDL_Event const event_;
};

}
}
}
}
}

#endif
