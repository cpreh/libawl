#ifndef AWL_BACKENDS_X11_WINDOW_PROPERTY_TYPE_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_PROPERTY_TYPE_FWD_HPP_INCLUDED

#include <awl/backends/x11/atom_fwd.hpp>
#include <fcppt/declare_strong_typedef.hpp>


namespace awl::backends::x11::window
{

FCPPT_DECLARE_STRONG_TYPEDEF(
	awl::backends::x11::atom,
	property_type
);

}

#endif
