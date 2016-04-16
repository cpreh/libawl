#include <awl/exception.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/registry.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::registry::registry(
	awl::backends::wayland::display const &_display
)
:
	ptr_{
		::wl_display_get_registry(
			_display.get()
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
				FCPPT_TEXT("wl_display_get_registry failed")
			};
}

awl::backends::wayland::registry::~registry()
{
	::wl_registry_destroy(
		ptr_
	);
}

wl_registry *
awl::backends::wayland::registry::get() const
{
	return
		ptr_;
}
