#include <awl/backends/wayland/cursor/convert_name.hpp>
#include <awl/backends/wayland/cursor/name.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

awl::backends::wayland::cursor::name
awl::backends::wayland::cursor::convert_name(awl::cursor::type const _type)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_type)
  {
  case awl::cursor::type::arrow:
    return awl::backends::wayland::cursor::name{std::string{"left_ptr"}};
  case awl::cursor::type::cross:
    return awl::backends::wayland::cursor::name{std::string{"xterm"}};
  case awl::cursor::type::hand:
    return awl::backends::wayland::cursor::name{std::string{"hand1"}};
  }
  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_type);
}
