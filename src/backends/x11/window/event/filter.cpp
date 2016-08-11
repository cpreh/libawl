#include <awl/backends/x11/window/const_optional_object_ref.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <fcppt/const.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


bool
awl::backends::x11::window::event::filter(
	awl::backends::x11::window::event::object _event,
	awl::backends::x11::window::const_optional_object_ref const _window
)
{
	return
		::XFilterEvent(
			&_event.get(),
			fcppt::optional::maybe(
				_window,
				fcppt::const_(
					fcppt::literal<
						Window
					>(
						None
					)
				),
				[](
					fcppt::reference<
						awl::backends::x11::window::object const
					> const _window_ref
				)
				{
					return
						_window_ref.get().get();
				}
			)
		)
		==
		True;

}
