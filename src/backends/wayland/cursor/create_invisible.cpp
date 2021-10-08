#include <awl/backends/wayland/cursor/create_invisible.hpp>
#include <awl/backends/wayland/cursor/invisible.hpp>
#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/object_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>

awl::backends::wayland::cursor::object_unique_ptr awl::backends::wayland::cursor::create_invisible()
{
  return fcppt::unique_ptr_to_base<awl::backends::wayland::cursor::object>(
      fcppt::make_unique_ptr<awl::backends::wayland::cursor::invisible>());
}
