#ifndef AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_DETAIL_SYMBOL
awl::backends::x11::visual::object_unique_ptr
visual(
	awl::backends::x11::window::base &
);

}
}
}
}

#endif
