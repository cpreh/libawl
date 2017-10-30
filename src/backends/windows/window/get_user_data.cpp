#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/get_long_ptr.hpp>
#include <awl/backends/windows/window/get_user_data.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/user_data_fwd.hpp>


awl::backends::windows::window::user_data const &
awl::backends::windows::window::get_user_data(
	HWND const _hwnd
)
{
	return
		*reinterpret_cast<
			awl::backends::windows::window::user_data const *
		>(
			awl::backends::windows::window::get_long_ptr(
				_hwnd,
				GWLP_USERDATA
			)
		);
}
