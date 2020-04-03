#include <awl/exception.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_dispatch_pending.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::wayland::display_dispatch_pending(
	awl::backends::wayland::display const &_display
)
{
	if(
		::wl_display_dispatch_pending(
			_display.get()
		)
		==
		-1
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("Display dispatch_pending failed")
			};
	}
}
