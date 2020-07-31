#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace seat
{

using
object_ref
=
fcppt::reference<
	awl::backends::wayland::system::seat::object
>;

}
}
}
}
}

#endif
