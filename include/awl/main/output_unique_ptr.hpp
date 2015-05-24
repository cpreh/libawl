#ifndef AWL_MAIN_OUTPUT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAIN_OUTPUT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/main/output_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace main
{

typedef
fcppt::unique_ptr<
	awl::main::output
>
output_unique_ptr;

}
}

#endif
