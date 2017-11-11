#include <awl/event/base.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>


awl::window::event::base::base(
	awl::window::reference const _window
)
:
	awl::event::base{},
	window_{
		_window
	}
{
}

awl::window::event::base::~base()
{
}

awl::window::object &
awl::window::event::base::window() const
{
	return
		window_.get();
}
