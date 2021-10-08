#include <awl/backends/wayland/cursor/convert_name.hpp>
#include <awl/backends/wayland/cursor/name.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

awl::backends::wayland::cursor::name
awl::backends::wayland::cursor::convert_name(awl::cursor::type const _type)
{
  switch (_type)
  {
  case awl::cursor::type::arrow:
    return awl::backends::wayland::cursor::name{std::string{"left_ptr"}};
  case awl::cursor::type::cross:
    return awl::backends::wayland::cursor::name{std::string{"xterm"}};
  case awl::cursor::type::hand:
    return awl::backends::wayland::cursor::name{std::string{"hand1"}};
  }

  FCPPT_ASSERT_UNREACHABLE;
}
