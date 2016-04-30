#include <awl/backends/windows/message.hpp>
#include <awl/backends/windows/optional_message.hpp>
#include <awl/backends/windows/peek_message.hpp>
#include <awl/backends/windows/windows.hpp>


awl::backends::windows::optional_message
awl::backends::windows::peek_message(
	HWND const _hwnd
)
{
	MSG msg;

	return
		::PeekMessage(
			&msg,
			_hwnd,
			0,
			0,
			PM_REMOVE
		)
		==
		0
		?
			awl::backends::windows::optional_message{}
		:
			awl::backends::windows::optional_message{
				awl::backends::windows::message{
					msg
				}
			}
		;
}
