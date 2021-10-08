#ifndef AWL_MAIN_OUTPUT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAIN_OUTPUT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/main/output_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl::main
{

using output_unique_ptr = fcppt::unique_ptr<awl::main::output>;

}

#endif
