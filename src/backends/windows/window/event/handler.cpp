#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/handler.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/bind.hpp>


awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::handler(
	awl::backends::windows::window::event::object const &_event
)
{
	switch(
		_event.type().get()
	)
	{
	case WM_CLOSE:
		return
			awl::backends::windows::window::event::return_type{
				0
			};
	case WM_SETCURSOR:
		return
			fcppt::optional::bind(
				_event.window().get().cursor(),
				[
					&_event
				](
					fcppt::reference<
						awl::backends::windows::cursor::object const
					> const _cursor
				)
				{
					if(
						LOWORD(
							_event.lparam().get()
						)
						==
						HTCLIENT
					)
					{
						::SetCursor(
							_cursor.get().get()
						);

						return
							awl::backends::windows::window::event::return_type(
								TRUE
							);
					}

					return
						awl::backends::windows::window::event::return_type();
				}
			);
	}

	return
		awl::backends::windows::window::event::return_type();
}
