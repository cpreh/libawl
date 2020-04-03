#ifndef AWL_BACKENDS_X11_WINDOW_OPTIONAL_CLASS_HINT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OPTIONAL_CLASS_HINT_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

using
optional_class_hint
=
fcppt::optional::object<
	awl::backends::x11::window::class_hint
>;

}
}
}
}

#endif
