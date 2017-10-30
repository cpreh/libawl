#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/get_user_data.hpp>
#include <awl/backends/windows/window/user_data.hpp>
#include <awl/backends/windows/window/event/make.hpp>
#include <awl/backends/windows/window/event/handler.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <awl/event/base.hpp>
#include <fcppt/optional/from.hpp>


LRESULT CALLBACK
awl::backends::windows::window::event::wnd_proc(
	HWND const _hwnd,
	UINT const _message,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	awl::backends::windows::window::user_data const &user_data{
		awl::backends::windows::window::get_user_data(
			_hwnd
		)
	};

	awl::backends::windows::window::event::object const event{
		user_data.window(),
		awl::backends::windows::message_type{
			_message
		},
		awl::backends::windows::wparam{
			_wparam
		},
		awl::backends::windows::lparam{
			_lparam
		}
	};

	user_data.events().get().push_back(
		awl::backends::windows::window::event::make(
			event
		)
	);

	return
		fcppt::optional::from(
			awl::backends::windows::window::event::handler(
				event
			),
			[
				_hwnd,
				_message,
				_wparam,
				_lparam
			]{
				return
					awl::backends::windows::default_wnd_proc(
						_hwnd,
						_message,
						_wparam,
						_lparam
					);
			}
		);
}
