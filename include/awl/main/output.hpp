#ifndef AWL_MAIN_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_OUTPUT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/output_fwd.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace main
{

class FCPPT_SYMBOL_CLASS output
{
	FCPPT_NONCOPYABLE(
		output
	);
protected:
	AWL_DETAIL_SYMBOL
	output();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~output() = 0;
};

}
}

#endif
