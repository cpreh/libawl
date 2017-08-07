#ifndef AWL_BACKENDS_POSIX_EVENT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_EVENT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/posix/event_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

typedef
fcppt::unique_ptr<
	awl::backends::posix::event
>
event_unique_ptr;

}
}
}

#endif
