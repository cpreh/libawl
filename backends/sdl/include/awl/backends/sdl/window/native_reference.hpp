#ifndef AWL_BACKENDS_SDL_WINDOW_NATIVE_REFERENCE_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_NATIVE_REFERENCE_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::sdl::window
{

using native_reference = fcppt::reference<SDL_Window>;

}

#endif
