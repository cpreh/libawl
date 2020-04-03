#ifndef AWL_CURSOR_HOTSPOT_FWD_HPP_INCLUDED
#define AWL_CURSOR_HOTSPOT_FWD_HPP_INCLUDED

#include <awl/cursor/size.hpp>
#include <fcppt/math/vector/static_fwd.hpp>


namespace awl
{
namespace cursor
{

using
hotspot
=
fcppt::math::vector::static_<
	awl::cursor::size,
	2
>;

}
}

#endif
