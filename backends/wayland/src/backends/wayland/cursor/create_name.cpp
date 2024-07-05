#include <awl/backends/wayland/cursor/create_name.hpp>
#include <awl/backends/wayland/cursor/name_fwd.hpp>
#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/object_unique_ptr.hpp>
#include <awl/backends/wayland/cursor/predefined.hpp>
#include <awl/backends/wayland/cursor/theme_fwd.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>

awl::backends::wayland::cursor::object_unique_ptr awl::backends::wayland::cursor::create_name(
    awl::backends::wayland::cursor::theme const &_theme,
    awl::backends::wayland::cursor::name const &_name)
{
  return fcppt::unique_ptr_to_base<awl::backends::wayland::cursor::object>(
      fcppt::make_unique_ptr<awl::backends::wayland::cursor::predefined>(_theme, _name));
}
