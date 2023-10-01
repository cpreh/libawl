#include <awl/show_error.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/platform.hpp> // NOLINT(misc-include-cleaner)
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/backends/windows/message_box.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#else
#include <fcppt/io/cerr.hpp>
#endif

void awl::show_error(fcppt::string const &_text)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
  awl::backends::windows::message_box(
      awl::backends::windows::window::const_optional_object_ref(),
      _text,
      FCPPT_TEXT("Error"),
      MB_OK | MB_ICONERROR);
#else
  fcppt::io::cerr() << _text << FCPPT_TEXT('\n');
#endif
}
