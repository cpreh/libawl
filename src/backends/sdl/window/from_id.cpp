#include <awl/backends/sdl/window/from_id.hpp>
#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

fcppt::optional::reference<SDL_Window> awl::backends::sdl::window::from_id(std::uint32_t const _id)
{
  return fcppt::optional::from_pointer(SDL_GetWindowFromID(_id));
}
