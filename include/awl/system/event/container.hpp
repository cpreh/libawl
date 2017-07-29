#ifndef AWL_SYSTEM_EVENT_CONTAINER_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_CONTAINER_HPP_INCLUDED

#include <awl/system/event/base_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef
std::vector<
	awl::system::event::base_unique_ptr
>
container;

}
}
}

#endif
