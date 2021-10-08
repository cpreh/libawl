#ifndef AWL_BACKENDS_WINDOWS_COMMAND_LINE_ARGV_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_COMMAND_LINE_ARGV_HPP_INCLUDED

#include <awl/backends/windows/command_line_argv_fwd.hpp>
#include <awl/backends/windows/command_line_ptr.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class command_line_argv
{
  FCPPT_NONCOPYABLE(command_line_argv);

public:
  command_line_argv(int argc, awl::backends::windows::command_line_ptr &&) noexcept;

  AWL_DETAIL_SYMBOL
  command_line_argv(command_line_argv &&) noexcept;

  AWL_DETAIL_SYMBOL
  command_line_argv &operator=(command_line_argv &&) noexcept;

  AWL_DETAIL_SYMBOL
  ~command_line_argv() noexcept;

  AWL_DETAIL_SYMBOL
  int argc() const noexcept;

  AWL_DETAIL_SYMBOL
  wchar_t **argv() const noexcept;

private:
  int argc_;

  awl::backends::windows::command_line_ptr argv_;
};

}
}
}

#endif
