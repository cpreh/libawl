#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/set_data.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <string>
#include <fcppt/config/external_end.hpp>

void awl::backends::sdl::window::set_data(
    awl::backends::sdl::window::native_reference const _window,
    std::string const &_name,
    void *const _data)
{
  SDL_SetWindowData(&_window.get(), _name.c_str(), _data);
}
