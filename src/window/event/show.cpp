#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/show.hpp>


awl::window::event::show::show(
	awl::window::reference const _window
)
:
	awl::window::event::base{
		_window
	}
{
}

awl::window::event::show::~show()
{
}
