#ifndef AWL_BACKENDS_X11_PIXMAP_DIM_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_DIM_FWD_HPP_INCLUDED

#include <awl/backends/x11/pixmap/size.hpp>
#include <fcppt/math/dim/static_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace pixmap
{

using
dim
=
fcppt::math::dim::static_<
	awl::backends::x11::pixmap::size,
	2
>;

}
}
}
}

#endif
