#include <awl/exception.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_read_events.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::wayland::display_read_events(
	awl::backends::wayland::display const &_display
)
{
	if(
		::wl_display_read_events(
			_display.get()
		)
		==
		-1
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("Display read_events failed")
			};
	}
}
