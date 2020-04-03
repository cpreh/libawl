#ifndef AWL_EVENT_OPTIONAL_BASE_UNIQUE_PTR_FWD_HPP_INCLUDED
#define AWL_EVENT_OPTIONAL_BASE_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <awl/event/base_unique_ptr.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace event
{

using
optional_base_unique_ptr
=
fcppt::optional::object<
	awl::event::base_unique_ptr
>;

}
}

#endif
