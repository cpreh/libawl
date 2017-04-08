#include <awl/exception.hpp>
#include <awl/backends/windows/command_line_argv.hpp>
#include <awl/backends/windows/command_line_ptr.hpp>
#include <awl/backends/windows/command_line_to_argv.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/text.hpp>


awl::backends::windows::command_line_argv
awl::backends::windows::command_line_to_argv(
	wchar_t const *const _command_line
)
noexcept(false)
{
	int argc{
		-1
	};

	LPWSTR* const result{
		::CommandLineToArgvW(
			_command_line,
			&argc
		)
	};

	if(
		result
		==
		NULL
	)
		throw
			awl::exception{
				FCPPT_TEXT("CommandLineToArgvW failed")
			};

	return
		awl::backends::windows::command_line_argv{
			argc,
			awl::backends::windows::command_line_ptr{
				result
			}
		};
}
