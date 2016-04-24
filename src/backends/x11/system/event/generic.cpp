#include <awl/backends/x11/system/event/generic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::event::generic::generic(
	XGenericEventCookie const &_event
)
:
	event_(
		_event
	)
{
}

XGenericEventCookie const &
awl::backends::x11::system::event::generic::get() const
{
	return
		event_;
}

XGenericEventCookie &
awl::backends::x11::system::event::generic::get()
{
	return
		event_;
}
