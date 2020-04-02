#include <awl/window/dim.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/resize.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::window::event::resize::resize(
	awl::window::reference const _window,
	awl::window::dim _dim
)
:
	awl::window::event::base{
		_window
	},
	dim_{
		std::move(
			_dim
		)
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
