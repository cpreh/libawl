#ifndef AWL_MAIN_OPTIONAL_SCOPED_OUTPUT_UNIQUE_PTR_FWD_HPP_INCLUDED
#define AWL_MAIN_OPTIONAL_SCOPED_OUTPUT_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <awl/main/scoped_output_unique_ptr.hpp>
#include <fcppt/optional/object_fwd.hpp>

namespace awl
{
namespace main
{

typedef fcppt::optional::object<awl::main::scoped_output_unique_ptr>
    optional_scoped_output_unique_ptr;

}
}

#endif
