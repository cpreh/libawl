#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/display_roundtrip.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/window/object.hpp>
#include <awl/backends/wayland/window/original_object.hpp>
#include <awl/backends/wayland/window/event/original_processor.hpp>
#include <awl/backends/wayland/window/event/processor.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/math/dim/null.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::window::original_object::original_object(
	awl::backends::wayland::display const &_display,
	awl::backends::wayland::compositor const &_compositor,
	awl::backends::wayland::shell const &_shell,
	awl::window::parameters const &_parameters
)
:
	awl::backends::wayland::window::object(),
	display_{
		_display
	},
	visual_{
		_parameters.visual()
	},
	surface_{
		_compositor
	},
	shell_surface_{
		_shell,
		surface_
	},
	processor_{
		fcppt::unique_ptr_to_base<
			awl::backends::wayland::window::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::wayland::window::event::original_processor
			>(
				shell_surface_
			)
		)
	},
	size_{},
	resize_connection_{
		processor_->resize_callback(
			awl::window::event::resize_callback{
				[
					this
				](
					awl::window::event::resize const &_event
				)
				{
					size_ =
						awl::window::optional_dim{
							_event.dim()
						};
				}
			}
		)
	}
{
	// TODO: We have to keep track of pointers that enter and set their cursors
	fcppt::optional::maybe_void(
		_parameters.title(),
		[
			&shell_surface = shell_surface_
		](
			fcppt::string const &_title
		)
		{
			::wl_shell_surface_set_title(
				shell_surface.get(),
				fcppt::to_std_string(
					_title
				).c_str()
			);
		}
	);

	fcppt::optional::maybe_void(
		_parameters.class_name(),
		[
			&shell_surface = shell_surface_
		](
			fcppt::string const &_class_name
		)
		{
			::wl_shell_surface_set_class(
				shell_surface.get(),
				fcppt::to_std_string(
					_class_name
				).c_str()
			);
		}
	);
}

awl::backends::wayland::window::original_object::~original_object()
{
}

void
awl::backends::wayland::window::original_object::show()
{
	::wl_shell_surface_set_toplevel(
		shell_surface_.get()
	);

	awl::backends::wayland::display_roundtrip(
		display_
	);
}

awl::window::dim
awl::backends::wayland::window::original_object::size() const
{
	return
		fcppt::optional::from(
			size_,
			[]{
				return
					fcppt::math::dim::null<
						awl::window::dim
					>();
			}
		);
}

awl::visual::object const &
awl::backends::wayland::window::original_object::visual() const
{
	return
		visual_;
}

awl::window::event::processor &
awl::backends::wayland::window::original_object::processor()
{
	return
		*processor_;
}

wl_surface *
awl::backends::wayland::window::original_object::surface() const
{
	return
		surface_.get();
}

wl_shell_surface *
awl::backends::wayland::window::original_object::get() const
{
	return
		shell_surface_.get();
}
