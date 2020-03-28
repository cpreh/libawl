#ifndef AWL_SYSTEM_EVENT_RESULT_FWD_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_RESULT_FWD_HPP_INCLUDED

#include <awl/event/container.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <fcppt/either/object_fwd.hpp>


namespace awl
{
namespace system
{
namespace event
{

using
result
=
fcppt::either::object<
	awl::main::exit_code,
	awl::event::container
>;

}
}
}

#endif
