#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/get_long_ptr.hpp>
#include <awl/backends/windows/window/get_user_data.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/reference.hpp>
#include <fcppt/make_ref.hpp>


awl::backends::windows::window::reference
awl::backends::windows::window::get_user_data(
	HWND const _hwnd
)
{
	return
		fcppt::make_ref(
			*reinterpret_cast<
				awl::backends::windows::window::object *
			>(
				awl::backends::windows::window::get_long_ptr(
					_hwnd,
					GWLP_USERDATA
				)
			)
		);
}
