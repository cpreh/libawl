#include <awl/backends/sdl/cursor/create_invisible.hpp>
#include <awl/backends/sdl/cursor/invisible.hpp>
#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/backends/sdl/cursor/object_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>

awl::backends::sdl::cursor::object_unique_ptr awl::backends::sdl::cursor::create_invisible()
{
  return fcppt::unique_ptr_to_base<awl::backends::sdl::cursor::object>(
      fcppt::make_unique_ptr<awl::backends::sdl::cursor::invisible>());
}
