#ifndef AWL_MAIN_OPTIONAL_EXIT_CODE_FWD_HPP_INCLUDED
#define AWL_MAIN_OPTIONAL_EXIT_CODE_FWD_HPP_INCLUDED

#include <awl/main/exit_code_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace main
{

typedef
fcppt::optional::object<
	awl::main::exit_code
>
optional_exit_code;

}
}

#endif
