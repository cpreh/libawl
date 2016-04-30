#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <fcppt/optional/object_impl.hpp>


LRESULT CALLBACK
awl::backends::windows::window::event::wnd_proc(
	HWND const _hwnd,
	UINT const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	awl::backends::windows::window::event::original_processor &processor(
		*reinterpret_cast<
			awl::backends::windows::window::event::original_processor *
		>(
			::GetWindowLongPtr(
				_hwnd,
				GWLP_USERDATA
			)
		)
	);

	{
		awl::backends::windows::window::event::return_type const ret(
			processor.execute_callback(
				awl::backends::windows::message_type{
					_msg
				},
				awl::backends::windows::wparam{
					_wparam
				},
				awl::backends::windows::lparam{
					_lparam
				}
			)
		);

		// TODO!
		if(
			ret.has_value()
		)
			return
				ret.get_unsafe();
	}

	return
		::DefWindowProc(
			_hwnd,
			_msg,
			_wparam,
			_lparam
		);
}
