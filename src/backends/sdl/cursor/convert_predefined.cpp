#include <awl/backends/sdl/cursor/convert_predefined.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_mouse.h>
#include <fcppt/config/external_end.hpp>

SDL_SystemCursor awl::backends::sdl::cursor::convert_predefined(awl::cursor::type const _type)
{
  switch (_type)
  {
  case awl::cursor::type::arrow:
    return SDL_SYSTEM_CURSOR_ARROW;
  case awl::cursor::type::cross:
    return SDL_SYSTEM_CURSOR_CROSSHAIR;
  case awl::cursor::type::hand:
    return SDL_SYSTEM_CURSOR_HAND;
  }

  FCPPT_ASSERT_UNREACHABLE;
}
