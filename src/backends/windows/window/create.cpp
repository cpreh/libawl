#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/window/adjusted_size.hpp>
#include <awl/backends/windows/window/create.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/maybe.hpp>


HWND
awl::backends::windows::window::create(
	awl::window::parameters const &_param,
	awl::backends::windows::wndclass &_wndclass
)
{
	DWORD const window_flags{
		WS_OVERLAPPEDWINDOW
	};

	awl::backends::windows::window::signed_dim const size{
		awl::backends::windows::window::adjusted_size(
			_param.size(),
			window_flags
		)
	};

	HWND const ret{
		CreateWindow(
			_wndclass.name().c_str(),
			fcppt::optional::maybe(
				_param.title(),
				[]()
				-> LPCTSTR
				{
					return
						nullptr;
				},
				[](
					fcppt::string const &_title
				)
				{
					return
						_title.c_str();
				}
			),
			window_flags,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			size.w(),
			size.h(),
			nullptr,
			nullptr,
			awl::backends::windows::module_handle(),
			nullptr
		)
	};

	if(
		!ret
	)
		throw
			awl::exception{
				FCPPT_TEXT("CreateWindow() failed!")
			};

	return
		ret;
}
