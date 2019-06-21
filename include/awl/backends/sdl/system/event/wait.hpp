#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_WAIT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_WAIT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
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
SDL_Event
wait();

}
}
}
}
}

#endif
