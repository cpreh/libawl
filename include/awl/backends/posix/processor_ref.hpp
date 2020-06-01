#ifndef AWL_BACKENDS_POSIX_PROCESSOR_REF_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_PROCESSOR_REF_HPP_INCLUDED

#include <awl/backends/posix/processor_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

using
processor_ref
=
fcppt::reference<
	awl::backends::posix::processor
>;

}
}
}

#endif
