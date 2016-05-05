#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/original_object.hpp>
#endif
#if defined(AWL_WAYLAND_BACKEND)
#include <awl/backends/wayland/system/original_object.hpp>
#endif
#if defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/original_object.hpp>
#endif
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


awl::system::object_unique_ptr
awl::system::create()
{
#if defined(AWL_X11_BACKEND)
	return
		fcppt::unique_ptr_to_base<
			awl::system::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::system::original_object
			>()
		);
#endif

	// FIXME: How do we implement fallbacks?
#if defined(AWL_WAYLAND_BACKEND)
	return
		fcppt::unique_ptr_to_base<
			awl::system::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::wayland::system::original_object
			>()
		);
#endif

#if defined(AWL_WINDOWS_BACKEND)
	return
		fcppt::unique_ptr_to_base<
			awl::system::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::system::original_object
			>()
		);
#endif
}
