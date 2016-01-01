#ifndef AWL_SYSTEM_OPTIONAL_EXIT_CODE_FWD_HPP_INCLUDED
#define AWL_SYSTEM_OPTIONAL_EXIT_CODE_FWD_HPP_INCLUDED

#include <awl/main/exit_code.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace system
{

typedef fcppt::optional::object<
	awl::main::exit_code
> optional_exit_code;

}
}

#endif
