#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_POLL_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_POLL_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::sdl::system::event
{

AWL_DETAIL_SYMBOL
fcppt::optional::object<SDL_Event> poll();

}

#endif
