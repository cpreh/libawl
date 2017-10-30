#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/set_long_ptr.hpp>
#include <awl/backends/windows/window/set_user_data.hpp>
#include <awl/backends/windows/window/user_data_fwd.hpp>


void
awl::backends::windows::window::set_user_data(
	HWND const _hwnd,
	awl::backends::windows::window::user_data const &_data
)
{
	awl::backends::windows::window::set_long_ptr(
		_hwnd,
		GWLP_USERDATA,
		reinterpret_cast<
			LONG_PTR
		>(
			&_data
		)
	);
}
