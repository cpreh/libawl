#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/base.hpp>
#include <awl/backends/windows/system/event/handle_ready.hpp>


awl::backends::windows::system::event::handle_ready::handle_ready(
	HANDLE const _handle
)
:
	awl::backends::windows::system::event::base{},
	handle_{
		_handle
	}
{
}

awl::backends::windows::system::event::handle_ready::~handle_ready()
{
}

HANDLE
awl::backends::windows::system::event::handle_ready::get() const
{
	return
		handle_;
}
