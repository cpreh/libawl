#ifndef AWL_MAIN_LOOP_FUNCTION_HPP_INCLUDED
#define AWL_MAIN_LOOP_FUNCTION_HPP_INCLUDED

#include <awl/event/base_fwd.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace main
{

typedef
fcppt::function<
	void (
		awl::event::base const &
	)
>
loop_function;

}
}

#endif
