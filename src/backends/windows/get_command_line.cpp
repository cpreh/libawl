#include <awl/backends/windows/get_command_line.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/char_type.hpp>

fcppt::char_type const *awl::backends::windows::get_command_line() noexcept
{
  return ::GetCommandLine();
}
