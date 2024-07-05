#ifndef AWL_BACKENDS_SDL_WINDOW_SET_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_SET_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/reference.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::sdl::window
{

AWL_DETAIL_SYMBOL
void
    set_object(awl::backends::sdl::window::native_reference, awl::backends::sdl::window::reference);

}

#endif
