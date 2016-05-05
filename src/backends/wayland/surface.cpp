#include <awl/exception.hpp>
#include <awl/backends/wayland/compositor.hpp>
#include <awl/backends/wayland/surface.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::surface::surface(
	awl::backends::wayland::compositor const &_compositor
)
:
	impl_{
		::wl_compositor_create_surface(
			_compositor.get()
		)
	}
{
	if(
		impl_
		==
		nullptr
	)
		throw
			awl::exception{
				FCPPT_TEXT("Creating a surface failed")
			};
}

awl::backends::wayland::surface::~surface()
{
	::wl_surface_destroy(
		impl_
	);
}

wl_surface *
awl::backends::wayland::surface::get() const
{
	return
		impl_;
}
