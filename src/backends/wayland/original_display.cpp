#include <awl/exception.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/original_display.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::original_display::original_display()
:
	awl::backends::wayland::display(),
	ptr_{
		::wl_display_connect(
			nullptr
		)
	}
{
	if(
		ptr_
		==
		nullptr
	)
		throw
			awl::exception{
				FCPPT_TEXT("wl_display_connect failed")
			};
}

wl_display *
awl::backends::wayland::original_display::get() const
{
	return
		ptr_;
}

awl::backends::wayland::original_display::~original_display()
{
	::wl_display_disconnect(
		ptr_
	);
}
