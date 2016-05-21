#ifndef AWL_BACKENDS_POSIX_POSTED_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_POSTED_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/posix/posted_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

typedef
fcppt::unique_ptr<
	awl::backends::posix::posted
>
posted_unique_ptr;

}
}
}

#endif
