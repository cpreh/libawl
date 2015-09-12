#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/optional_object_unique_ptr.hpp>
#include <awl/backends/windows/window/wrapped_object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


awl::backends::windows::window::optional_object_unique_ptr
awl::backends::windows::get_focus()
{
	HWND const ret(
		::GetFocus()
	);

	return
		ret
		==
		nullptr
		?
			awl::backends::windows::window::optional_object_unique_ptr()
		:
			awl::backends::windows::window::optional_object_unique_ptr(
				fcppt::unique_ptr_to_base<
					awl::backends::windows::window::object
				>(
					fcppt::make_unique_ptr<
						awl::backends::windows::window::wrapped_object
					>(
						ret
					)
				)
			)
		;
}

