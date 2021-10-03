#ifndef AWL_MAIN_FUNCTION_CONTEXT_HPP_INCLUDED
#define AWL_MAIN_FUNCTION_CONTEXT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/args_char.hpp>


namespace awl::main
{

class function_context
{
public:
	AWL_DETAIL_SYMBOL
	function_context(
		int argc,
		fcppt::args_char **
	);

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	int
	argc() const;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	fcppt::args_char **
	argv() const;
private:
	int argc_;

	fcppt::args_char **argv_;
};

}

#endif

