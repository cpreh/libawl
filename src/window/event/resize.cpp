#include <awl/window/dim.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/resize.hpp>


awl::window::event::resize::resize(
	awl::window::reference const _window,
	awl::window::dim const _dim
)
:
	awl::window::event::base{
		_window
	},
	dim_{
		_dim
	}
{
}

awl::window::event::resize::~resize()
= default;

awl::window::dim const &
awl::window::event::resize::dim() const
{
	return
		dim_;
}
