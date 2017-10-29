#include <awl/exception.hpp>
#include <awl/backends/windows/clear_last_error.hpp>
#include <awl/backends/windows/has_last_error.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/get_long_ptr.hpp>
#include <fcppt/text.hpp>


LONG_PTR
awl::backends::windows::window::get_long_ptr(
	HWND const _hwnd,
	int const _index
)
{
	awl::backends::windows::clear_last_error();

	LONG_PTR const result{
		::GetWindowLongPtr(
			_hwnd,
			_index
		)
	};

	if(
		result
		==
		0
		&&
		awl::backends::windows::has_last_error()
	)
		throw
			awl::exception{
				FCPPT_TEXT("GetWindowLongPtr failed")
			};

	return
		result;
}
