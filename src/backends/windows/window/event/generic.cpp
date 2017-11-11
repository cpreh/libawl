#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/reference.hpp>
#include <awl/backends/windows/window/event/generic.hpp>
#include <awl/window/object.hpp>
#include <awl/window/event/base.hpp>
#include <fcppt/reference_to_base.hpp>


awl::backends::windows::window::event::generic::generic(
	awl::backends::windows::window::reference const _window,
	awl::backends::windows::message_type const _type,
	awl::backends::windows::wparam const _wparam,
	awl::backends::windows::lparam const _lparam
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
	type_{
		_type
	},
	wparam_{
		_wparam
	},
	lparam_{
		_lparam
	}
{
}

awl::backends::windows::window::event::generic::~generic()
{
}

awl::backends::windows::window::reference
awl::backends::windows::window::event::generic::get() const
{
	return
		window_;
}

awl::backends::windows::message_type
awl::backends::windows::window::event::generic::type() const
{
	return
		type_;
}

awl::backends::windows::wparam
awl::backends::windows::window::event::generic::wparam() const
{
	return
		wparam_;
}

awl::backends::windows::lparam
awl::backends::windows::window::event::generic::lparam() const
{
	return
		lparam_;
}
