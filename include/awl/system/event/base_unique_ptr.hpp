#ifndef AWL_SYSTEM_EVENT_BASE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_BASE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/event/base_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef
fcppt::unique_ptr<
	awl::system::event::base
>
base_unique_ptr;

}
}
}

#endif
