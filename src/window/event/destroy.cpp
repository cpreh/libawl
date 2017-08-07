#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/destroy.hpp>


awl::window::event::destroy::destroy(
	awl::window::reference const _window
)
:
	awl::window::event::base{
		_window
	}
{
}

awl::window::event::destroy::~destroy()
{
}
