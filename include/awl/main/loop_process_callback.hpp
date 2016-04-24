#ifndef AWL_MAIN_LOOP_PROCESS_CALLBACK_HPP_INCLUDED
#define AWL_MAIN_LOOP_PROCESS_CALLBACK_HPP_INCLUDED

#include <awl/main/optional_exit_code_fwd.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace main
{

typedef
fcppt::function<
	awl::main::optional_exit_code ()
>
loop_process_callback;

}
}

#endif
