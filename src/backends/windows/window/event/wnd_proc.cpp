#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/get_user_data.hpp>
#include <awl/backends/windows/window/event/handler.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <fcppt/optional/from.hpp>


LRESULT CALLBACK
awl::backends::windows::window::event::wnd_proc(
	HWND const _hwnd,
	UINT const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	return
		fcppt::optional::from(
			awl::backends::windows::window::event::handler(
				awl::backends::windows::window::event::object{
					awl::backends::windows::window::get_user_data(
						_hwnd
					),
					awl::backends::windows::message_type{
						_msg
					},
					awl::backends::windows::wparam{
						_wparam
					},
					awl::backends::windows::lparam{
						_lparam
					}
				}
			),
			[
				_hwnd,
				_msg,
				_wparam,
				_lparam
			]{
				return
					::DefWindowProc(
						_hwnd,
						_msg,
						_wparam,
						_lparam
					);
			}
		);
}
