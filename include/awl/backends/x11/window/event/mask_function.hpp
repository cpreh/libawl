#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_MASK_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_MASK_FUNCTION_HPP_INCLUDED

#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

using
mask_function
=
fcppt::function<
	void (
		awl::backends::x11::window::event::mask_bit
	)
>;

}
}
}
}
}

#endif
