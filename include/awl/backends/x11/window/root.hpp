#ifndef AWL_BACKENDS_X11_WINDOW_ROOT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ROOT_HPP_INCLUDED

#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/window/base_unique_ptr.hpp>
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
awl::backends::x11::window::base_unique_ptr
root(
	awl::backends::x11::display_ref,
	awl::backends::x11::screen
);

}
}
}
}

#endif
