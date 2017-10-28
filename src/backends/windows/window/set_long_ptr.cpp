#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/set_long_ptr.hpp>
#include <fcppt/text.hpp>


void
awl::backends::windows::window::set_long_ptr(
	HWND const _hwnd,
	int const _index,
	LONG_PTR const _value
)
{
	if(
		::SetWindowLongPtr(
			_hwnd,
			_index,
			_value
		)
		==
		0
	)
		throw
			awl::exception{
				FCPPT_TEXT("SetWindowLongPtr failed")
			};
}
