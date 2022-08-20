#include <awl/exception.hpp>
#include <awl/backends/sdl/window/get_data.hpp>
#include <awl/backends/sdl/window/get_object.hpp>
#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/object_data_name.hpp>
#include <awl/backends/sdl/window/object_fwd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/optional/to_exception.hpp>

awl::backends::sdl::window::object &
awl::backends::sdl::window::get_object(awl::backends::sdl::window::native_reference const _window)
{
  return *fcppt::cast::from_void_ptr<awl::backends::sdl::window::object *>(
      fcppt::optional::to_exception(
          awl::backends::sdl::window::get_data(
              _window, awl::backends::sdl::window::object_data_name()),
          [] { return awl::exception{FCPPT_TEXT("SDL window data not found.")}; }));
}
