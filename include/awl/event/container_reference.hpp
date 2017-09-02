#ifndef AWL_EVENT_CONTAINER_REFERENCE_HPP_INCLUDED
#define AWL_EVENT_CONTAINER_REFERENCE_HPP_INCLUDED

#include <awl/event/container.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace event
{

typedef
fcppt::reference<
	awl::event::container
>
container_reference;

}
}

#endif
