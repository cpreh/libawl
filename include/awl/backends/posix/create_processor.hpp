#ifndef AWL_BACKENDS_POSIX_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/backends/posix/processor_unique_ptr.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::posix
{

AWL_DETAIL_SYMBOL
awl::backends::posix::processor_unique_ptr
create_processor();

}

#endif
