#ifndef AWL_BACKENDS_SDL_WINDOW_FROM_ID_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_FROM_ID_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::sdl::window
{

AWL_DETAIL_SYMBOL
fcppt::optional::reference<SDL_Window> from_id(std::uint32_t);

}

#endif
