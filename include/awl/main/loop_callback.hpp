#ifndef AWL_MAIN_LOOP_CALLBACK_HPP_INCLUDED
#define AWL_MAIN_LOOP_CALLBACK_HPP_INCLUDED

#include <fcppt/function_impl.hpp>


namespace awl
{
namespace main
{

typedef
fcppt::function<
	void ()
>
loop_callback;

}
}

#endif
