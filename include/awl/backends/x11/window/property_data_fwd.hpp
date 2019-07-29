#ifndef AWL_BACKENDS_X11_WINDOW_PROPERTY_DATA_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_PROPERTY_DATA_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/basic_property_data_fwd.hpp>
#include <fcppt/variant/variadic_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef
fcppt::variant::variadic<
	awl::backends::x11::window::basic_property_data<
		char
	>,
	awl::backends::x11::window::basic_property_data<
		short
	>,
	awl::backends::x11::window::basic_property_data<
		long
	>
>
property_data;

}
}
}
}

#endif
