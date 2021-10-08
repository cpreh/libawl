#ifndef AWL_BACKENDS_SDL_WINDOW_GET_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_GET_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/object_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::sdl::window
{

AWL_DETAIL_SYMBOL
awl::backends::sdl::window::object &get_object(awl::backends::sdl::window::native_reference);

}

#endif
