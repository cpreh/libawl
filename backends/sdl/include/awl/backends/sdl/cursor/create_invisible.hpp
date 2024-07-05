#ifndef AWL_BACKENDS_SDL_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object_unique_ptr.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::sdl::cursor
{

AWL_DETAIL_SYMBOL
awl::backends::sdl::cursor::object_unique_ptr create_invisible();

}

#endif
