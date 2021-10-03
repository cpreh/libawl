#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_PUSH_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_PUSH_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl::backends::sdl::system::event
{

[[nodiscard]]
AWL_DETAIL_SYMBOL
fcppt::either::error<
	fcppt::optional::object<
		std::string
	>
>
push(
	SDL_Event const &
);

}

#endif
