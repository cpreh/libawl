#include <awl/backends/sdl/get_error.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_error.h>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::optional::object<std::string> awl::backends::sdl::get_error()
{
  std::string error{SDL_GetError()};

  return fcppt::optional::make_if(!error.empty(), [&error] { return std::move(error); });
}
