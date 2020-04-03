#ifndef AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/colormap_fwd.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/const_optional_object_ref_fwd.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/optional_dim_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_DETAIL_SYMBOL
Window
create(
	awl::window::optional_dim const &,
	awl::backends::x11::display_ref,
	awl::backends::x11::screen,
	awl::backends::x11::colormap const &,
	awl::backends::x11::visual::object const &,
	awl::backends::x11::cursor::const_optional_object_ref const &
);

}
}
}
}

#endif
