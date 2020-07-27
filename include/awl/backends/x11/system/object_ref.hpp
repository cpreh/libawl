#ifndef AWL_BACKENDS_X11_SYSTEM_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/x11/system/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{

using
object_ref
=
fcppt::reference<
	awl::backends::x11::system::object
>;

}
}
}
}

#endif
