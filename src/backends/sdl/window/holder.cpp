#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/window/holder.hpp>
#include <awl/backends/sdl/window/native_reference.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>

awl::backends::sdl::window::holder::holder(SDL_Window *const _window) : window_{_window}
{
  if (this->window_ == nullptr)
  {
    throw awl::backends::sdl::exception{FCPPT_TEXT("SDL_CreateWindow failed")};
  }
}

awl::backends::sdl::window::holder::~holder() { SDL_DestroyWindow(this->window_); }

awl::backends::sdl::window::native_reference awl::backends::sdl::window::holder::get() const
{
  return fcppt::make_ref(*this->window_);
}
