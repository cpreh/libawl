#ifndef AWL_SYSTEM_EVENT_PROCESSOR_REF_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_REF_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace system
{
namespace event
{

using
processor_ref
=
fcppt::reference<
	awl::system::event::processor
>;

}
}
}

#endif
