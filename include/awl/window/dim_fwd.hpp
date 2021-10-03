#ifndef AWL_WINDOW_DIM_FWD_HPP_INCLUDED
#define AWL_WINDOW_DIM_FWD_HPP_INCLUDED

#include <awl/window/size.hpp>
#include <fcppt/math/dim/static_fwd.hpp>


namespace awl::window
{

using
dim
=
fcppt::math::dim::static_<
	awl::window::size,
	2
>;

}

#endif
