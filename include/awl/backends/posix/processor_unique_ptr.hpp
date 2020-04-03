#ifndef AWL_BACKENDS_POSIX_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/posix/processor_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

using
processor_unique_ptr
=
fcppt::unique_ptr<
	awl::backends::posix::processor
>;

}
}
}

#endif
