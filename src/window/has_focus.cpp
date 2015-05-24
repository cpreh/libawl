#include <awl/system/object.hpp>
#include <awl/window/has_focus.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/optional_object_unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/maybe.hpp>


bool
awl::window::has_focus(
	awl::system::object &_system,
	awl::window::object const &_window
)
{
	awl::window::optional_object_unique_ptr const focus_window(
		_system.focus_window()
	);

	return
		fcppt::maybe(
			focus_window,
			fcppt::const_(
				false
			),
			[
				&_window
			](
				awl::window::object_unique_ptr const &_focus
			)
			{
				return
					_window.equal_to(
						*_focus
					);
			}
		);
}
