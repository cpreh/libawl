#ifndef AWL_BACKENDS_WINDOWS_COMMAND_LINE_TO_ARGV_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_COMMAND_LINE_TO_ARGV_HPP_INCLUDED

#include <awl/backends/windows/command_line_argv.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

// TODO: string_view
AWL_DETAIL_SYMBOL
awl::backends::windows::command_line_argv
command_line_to_argv(
	wchar_t const *
)
noexcept(false);

}
}
}

#endif
