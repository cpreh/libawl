#ifndef AWL_BACKENDS_WINDOWS_EVENT_OPTIONAL_MESSAGE_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_OPTIONAL_MESSAGE_FWD_HPP_INCLUDED

#include <awl/backends/windows/event/message_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

typedef
fcppt::optional::object<
	awl::backends::windows::event::message
>
optional_message;

}
}
}
}

#endif
