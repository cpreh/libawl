#ifndef AWL_BACKENDS_X11_WINDOW_CHANGE_PROPERTY_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CHANGE_PROPERTY_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/property_data_fwd.hpp>
#include <awl/backends/x11/window/property_fwd.hpp>
#include <awl/backends/x11/window/property_mode_fwd.hpp>
#include <awl/backends/x11/window/property_type_fwd.hpp>
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
void
change_property(
	awl::backends::x11::window::base const &,
	awl::backends::x11::window::property,
	awl::backends::x11::window::property_type,
	awl::backends::x11::window::property_mode,
	awl::backends::x11::window::property_data const &
);

}
}
}
}

#endif
