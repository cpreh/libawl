#ifndef AWL_BACKENDS_X11_WINDOW_GET_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_GET_CLASS_HINT_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/window/optional_class_hint.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_DETAIL_SYMBOL
awl::backends::x11::window::optional_class_hint
get_class_hint(
	awl::backends::x11::display const &,
	Window
);

}
}
}
}

#endif