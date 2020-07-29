#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/wayland/system/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{

using
object_ref
=
fcppt::reference<
	awl::backends::wayland::system::object
>;

}
}
}
}

#endif
