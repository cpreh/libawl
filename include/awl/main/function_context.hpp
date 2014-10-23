#ifndef AWL_MAIN_FUNCTION_CONTEXT_HPP_INCLUDED
#define AWL_MAIN_FUNCTION_CONTEXT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>


namespace awl
{
namespace main
{
class function_context
{
public:
	AWL_DETAIL_SYMBOL
	explicit
	function_context(
		int argc,
		char *argv[]);

	AWL_DETAIL_SYMBOL
	int
	argc() const;

	AWL_DETAIL_SYMBOL
	char**
	argv() const;
private:
	int argc_;
	char **argv_;
};
}
}

#endif

