#include <awl/backends/sdl/cursor/create_predefined.hpp>
#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/backends/sdl/cursor/object_unique_ptr.hpp>
#include <awl/backends/sdl/cursor/predefined.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>

awl::backends::sdl::cursor::object_unique_ptr
awl::backends::sdl::cursor::create_predefined(awl::cursor::type const _type)
{
  return fcppt::unique_ptr_to_base<awl::backends::sdl::cursor::object>(
      fcppt::make_unique_ptr<awl::backends::sdl::cursor::predefined>(_type));
}
