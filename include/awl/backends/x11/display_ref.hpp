#ifndef AWL_BACKENDS_X11_DISPLAY_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_REF_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <fcppt/reference_impl.hpp>

namespace awl::backends::x11
{

using display_ref = fcppt::reference<awl::backends::x11::display>;

}

#endif
