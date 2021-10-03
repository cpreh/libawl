#ifndef AWL_BACKENDS_X11_WINDOW_PROPERTY_DATA_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_PROPERTY_DATA_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/basic_property_data_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>


namespace awl::backends::x11::window
{

using
property_data
=
fcppt::variant::object<
	awl::backends::x11::window::basic_property_data<
		char
	>,
	awl::backends::x11::window::basic_property_data<
		short // NOLINT(google-runtime-int)
	>,
	awl::backends::x11::window::basic_property_data<
		long // NOLINT(google-runtime-int)
	>
>;

}

#endif
