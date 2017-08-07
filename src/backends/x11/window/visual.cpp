#include <awl/backends/x11/visual/create_info.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/visual/wrapped.hpp>
#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/visual.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


awl::backends::x11::visual::object_unique_ptr
awl::backends::x11::window::visual(
	awl::backends::x11::window::base &_window
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::backends::x11::visual::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::visual::wrapped
			>(
				awl::backends::x11::visual::create_info(
					_window.display(),
					*awl::backends::x11::window::attributes(
						_window
					).visual
				)
			)
		);
}
