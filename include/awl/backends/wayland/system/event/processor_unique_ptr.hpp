#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/wayland/system/event/processor_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

using
processor_unique_ptr
=
fcppt::unique_ptr<
	awl::backends::wayland::system::event::processor
>;

}
}
}
}
}

#endif
