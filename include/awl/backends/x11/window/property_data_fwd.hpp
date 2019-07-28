#ifndef AWL_BACKENDS_X11_WINDOW_PROPERTY_DATA_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_PROPERTY_DATA_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/basic_property_data_fwd.hpp>
#include <fcppt/variant/variadic_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


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
		std::uint8_t
	>,
	awl::backends::x11::window::basic_property_data<
		std::uint16_t
	>,
	awl::backends::x11::window::basic_property_data<
		std::uint32_t
	>
>
property_data;

}
}
}
}

#endif
