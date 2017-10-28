#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_HOLDER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_HOLDER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle_holder_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

typedef
fcppt::unique_ptr<
	awl::backends::windows::system::event::handle_holder
>
handle_holder_unique_ptr;

}
}
}
}
}

#endif
