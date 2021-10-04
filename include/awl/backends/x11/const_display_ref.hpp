#ifndef AWL_BACKENDS_X11_CONST_DISPLAY_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_CONST_DISPLAY_REF_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl::backends::x11
{

using
const_display_ref
=
fcppt::reference<
	awl::backends::x11::display const
>;

}

#endif
