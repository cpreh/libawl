#ifndef AWL_WINDOW_OPTIONAL_POS_FWD_HPP_INCLUDED
#define AWL_WINDOW_OPTIONAL_POS_FWD_HPP_INCLUDED

#include <awl/window/pos_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace window
{

typedef fcppt::optional::object<
	awl::window::pos
> optional_pos;

}
}

#endif
