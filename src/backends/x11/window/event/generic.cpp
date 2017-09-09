#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/object_ref.hpp>
#include <awl/backends/x11/window/event/generic.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/window/event/base.hpp>
#include <fcppt/reference_to_base.hpp>


awl::backends::x11::window::event::generic::generic(
	awl::backends::x11::window::object_ref const _window,
	awl::backends::x11::window::event::object const &_event
)
:
	awl::window::event::base{
		fcppt::reference_to_base<
			awl::window::object
		>(
			_window
		)
	},
	window_{
		_window
	},
	event_{
		_event
	}
{
}

awl::backends::x11::window::event::generic::~generic()
{
}

awl::backends::x11::window::object &
awl::backends::x11::window::event::generic::window() const
{
	return
		window_.get();
}

awl::backends::x11::window::event::object const &
awl::backends::x11::window::event::generic::event() const
{
	return
		event_;
}
