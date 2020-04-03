#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>


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

class object
{
public:
	AWL_DETAIL_SYMBOL
	explicit
	object(
		XEvent const &
	);

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	XEvent const &
	get() const;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	XEvent &
	get();
private:
	XEvent event_;
};

}
}
}
}
}

#endif
