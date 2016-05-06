#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/window/has_focus.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/object_unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/optional/maybe.hpp>


bool
awl::backends::windows::window::has_focus(
	awl::backends::windows::window::object const &_window
)
{
	return
		fcppt::optional::maybe(
			awl::backends::windows::get_focus(),
			fcppt::const_(
				false
			),
			[
				&_window
			](
				awl::backends::windows::window::object_unique_ptr &&_other
			)
			{
				return
					_other->hwnd()
					==
					_window.hwnd();
			}
		);
}
