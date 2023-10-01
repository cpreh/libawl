#include <awl/show_message_narrow.hpp>
#include <fcppt/config/platform.hpp> // NOLINT(misc-include-cleaner)
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/backends/windows/message_box_narrow.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <string>
#if !defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <iostream>
#include <ostream>
#endif
#include <fcppt/config/external_end.hpp>

void awl::show_message_narrow(std::string const &_text)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
  awl::backends::windows::message_box_narrow(
      awl::backends::windows::window::const_optional_object_ref(),
      _text,
      "Info",
      MB_OK | MB_ICONINFORMATION);
#else
  std::clog << _text << '\n';
#endif
}
