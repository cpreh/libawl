#ifndef AWL_BACKENDS_X11_WINDOW_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

using
const_optional_object_ref
=
fcppt::optional::reference<
	awl::backends::x11::window::object const
>;

}
}
}
}

#endif
