#include <awl/backends/windows/command_line_argv.hpp>
#include <awl/backends/windows/command_line_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::command_line_argv::command_line_argv(
	int const _argc,
	awl::backends::windows::command_line_ptr &&_argv
)
noexcept
:
	argc_{
		_argc
	},
	argv_{
		std::move(
			_argv
		)
	}
{
}

awl::backends::windows::command_line_argv::command_line_argv(
	command_line_argv &&
)
noexcept
=
default;

awl::backends::windows::command_line_argv &
awl::backends::windows::command_line_argv::operator=(
	command_line_argv &&
)
noexcept
=
default;

awl::backends::windows::command_line_argv::~command_line_argv()
noexcept
{
}

int
awl::backends::windows::command_line_argv::argc() const
noexcept
{
	return
		argc_;
}

wchar_t const *const *
awl::backends::windows::command_line_argv::argv() const
noexcept
{
	return
		argv_.get_pointer();
}
