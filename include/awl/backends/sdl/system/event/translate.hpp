#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_TRANSLATE_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_TRANSLATE_HPP_INCLUDED

#include <awl/backends/sdl/system/event/timer_type_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base_unique_ptr.hpp>
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

AWL_DETAIL_SYMBOL
awl::event::base_unique_ptr
translate(
	awl::backends::sdl::system::event::timer_type,
	SDL_Event const &
);

}
}
}
}
}

#endif
