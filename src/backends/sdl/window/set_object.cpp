#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/object_data_name.hpp>
#include <awl/backends/sdl/window/reference.hpp>
#include <awl/backends/sdl/window/set_data.hpp>
#include <awl/backends/sdl/window/set_object.hpp>

void awl::backends::sdl::window::set_object(
    awl::backends::sdl::window::native_reference const _window,
    awl::backends::sdl::window::reference const _ref)
{
  awl::backends::sdl::window::set_data(
      _window, awl::backends::sdl::window::object_data_name(), &_ref.get());
}
