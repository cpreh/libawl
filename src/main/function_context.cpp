#include <awl/main/function_context.hpp>
#include <fcppt/args_char.hpp>


awl::main::function_context::function_context(
	int const _argc,
	fcppt::args_char const *const *const _argv
)
:
	argc_(
		_argc
	),
	argv_(
		_argv
	)
{
}

int
awl::main::function_context::argc() const
{
	return
		argc_;
}

fcppt::args_char const *const *
awl::main::function_context::argv() const
{
	return
		argv_;
}
