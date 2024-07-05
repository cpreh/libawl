#ifndef AWL_BACKENDS_SDL_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_HOLDER_HPP_INCLUDED

#include <awl/backends/sdl/window/native_reference.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::sdl::window
{

class holder
{
  FCPPT_NONMOVABLE(holder);

public:
  explicit holder(SDL_Window *);

  ~holder();

  [[nodiscard]] awl::backends::sdl::window::native_reference get() const;

private:
  SDL_Window *const window_;
};

}

#endif
