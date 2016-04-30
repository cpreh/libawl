#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/event/object.hpp>


awl::backends::windows::window::event::object::object(
	awl::backends::windows::wparam const _wparam,
	awl::backends::windows::lparam const _lparam
)
:
	wparam_(
		_wparam
	),
	lparam_(
		_lparam
	)
{
}

awl::backends::windows::wparam
awl::backends::windows::window::event::object::wparam() const
{
	return
		wparam_;
}

awl::backends::windows::lparam
awl::backends::windows::window::event::object::lparam() const
{
	return
		lparam_;
}
