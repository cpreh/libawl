#ifndef AWL_BACKENDS_SDL_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED

#include <awl/cursor/type_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_mouse.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::sdl::cursor
{

AWL_DETAIL_SYMBOL
SDL_SystemCursor convert_predefined(awl::cursor::type);

}

#endif
