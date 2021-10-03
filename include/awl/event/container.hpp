#ifndef AWL_EVENT_CONTAINER_HPP_INCLUDED
#define AWL_EVENT_CONTAINER_HPP_INCLUDED

#include <awl/event/base_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl::event
{

using
container
=
std::vector<
	awl::event::base_unique_ptr
>;

}

#endif
