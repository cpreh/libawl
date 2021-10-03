#ifndef AWL_BACKENDS_X11_VISUAL_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_MASK_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>


namespace awl::backends::x11::visual
{

FCPPT_MAKE_STRONG_TYPEDEF(
	long, // NOLINT(google-runtime-int)
	mask
);

}

#endif
