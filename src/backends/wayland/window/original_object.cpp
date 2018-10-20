#include <awl/exception.hpp>
#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/display_roundtrip.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/window/object.hpp>
#include <awl/backends/wayland/window/original_object.hpp>
#include <awl/backends/wayland/window/event/data.hpp>
#include <awl/event/base.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/resize.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/math/dim/null.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdint.h>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


namespace
{

void
shell_surface_ping(
	void *,
	wl_shell_surface *const _shell_surface,
	uint32_t _serial
)
{
	::wl_shell_surface_pong(
		_shell_surface,
		_serial
	);
}

void
shell_surface_configure(
	void *const _data,
	wl_shell_surface *,
	uint32_t,
	int32_t const _width,
	int32_t const _height
)
{
	awl::backends::wayland::window::event::data &data{
		*fcppt::cast::from_void_ptr<
			awl::backends::wayland::window::event::data *
		>(
			_data
		)
	};

	FCPPT_ASSERT_PRE(
		_width
		>=
		0
	);

	FCPPT_ASSERT_PRE(
		_height
		>=
		0
	);

	awl::window::dim const size{
		fcppt::cast::to_unsigned(
			_width
		),
		fcppt::cast::to_unsigned(
			_height
		)
	};

	FCPPT_LOG_DEBUG(
		data.log_,
		fcppt::log::out
			<<
			FCPPT_TEXT("Got resize event ")
			<<
			size
	);

	data.size_ =
		awl::window::optional_dim{
			size
		};

	data.events_.get().push_back(
		fcppt::unique_ptr_to_base<
			awl::event::base
		>(
			fcppt::make_unique_ptr<
				awl::window::event::resize
			>(
				data.reference_,
				size
			)
		)
	);

	// TODO: Add hide and show events
}

void
shell_surface_popup_done(
	void *,
	wl_shell_surface *
)
{
}

wl_shell_surface_listener const shell_surface_listener{
	shell_surface_ping,
	shell_surface_configure,
	shell_surface_popup_done
};

}

awl::backends::wayland::window::original_object::original_object(
	fcppt::log::object &_log,
	awl::event::container_reference const _events,
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
	data_{
		_log,
		fcppt::reference_to_base<
			awl::window::object
		>(
			fcppt::make_ref(
				*this
			)
		),
		_events
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
				fcppt::optional::to_exception(
					fcppt::to_std_string(
						_title
					),
					[
						&_title
					]{
						return
							awl::exception{
								FCPPT_TEXT("Failed to convert window title: ")
								+
								_title
							};
					}
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
				fcppt::optional::to_exception(
					fcppt::to_std_string(
						_class_name
					),
					[
						&_class_name
					]{
						return
							awl::exception{
								FCPPT_TEXT("Failed to convert class name: ")
								+
								_class_name
							};
					}
				).c_str()
			);
		}
	);

	::wl_shell_surface_add_listener(
		shell_surface_.get(),
		&shell_surface_listener,
		&data_
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
			data_.size_,
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
