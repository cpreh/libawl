#include <awl/backends/sdl/cursor/convert_predefined.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_mouse.h>
#include <fcppt/config/external_end.hpp>

SDL_SystemCursor awl::backends::sdl::cursor::convert_predefined(awl::cursor::type const _type)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_type)
  {
  case awl::cursor::type::arrow:
    return SDL_SYSTEM_CURSOR_ARROW;
  case awl::cursor::type::cross:
    return SDL_SYSTEM_CURSOR_CROSSHAIR;
  case awl::cursor::type::hand:
    return SDL_SYSTEM_CURSOR_HAND;
  }
  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_type);
}
