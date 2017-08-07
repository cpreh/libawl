#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/system/event/generic.hpp>
#include <awl/event/base.hpp>


awl::backends::x11::system::event::generic::generic(
	awl::backends::x11::display_ref const _display,
	XGenericEventCookie const &_event
)
:
	awl::event::base(),
	display_{
		_display
	},
	event_(
		_event
	)
{
}

awl::backends::x11::system::event::generic::~generic()
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

awl::backends::x11::display &
awl::backends::x11::system::event::generic::display() const
{
	return
		display_.get();
}
