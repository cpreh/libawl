#ifndef AWL_BACKENDS_POSIX_EVENT_CONTAINER_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_EVENT_CONTAINER_HPP_INCLUDED

#include <awl/backends/posix/event_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

typedef
std::vector<
	awl::backends::posix::event_unique_ptr
>
event_container;

}
}
}

#endif
