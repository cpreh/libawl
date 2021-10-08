#ifndef AWL_MAIN_SCOPED_OUTPUT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAIN_SCOPED_OUTPUT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/main/scoped_output_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace main
{

typedef fcppt::unique_ptr<awl::main::scoped_output> scoped_output_unique_ptr;

}
}

#endif
