#ifndef AWL_BACKENDS_X11_WINDOW_GET_GEOMETRY_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_GET_GEOMETRY_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/rect.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

awl::backends::x11::window::rect
get_geometry(
	awl::backends::x11::window::base const &
);

}
}
}
}

#endif
