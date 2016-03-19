#ifndef AWL_BACKENDS_X11_WINDOW_CONST_OPTIONAL_CLASS_HINT_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CONST_OPTIONAL_CLASS_HINT_REF_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef
fcppt::optional::reference<
	awl::backends::x11::window::class_hint const
>
const_optional_class_hint_ref;

}
}
}
}

#endif
