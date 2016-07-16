#include <awl/backends/wayland/window/shell_surface.hpp>
#include <awl/backends/wayland/window/event/data.hpp>
#include <awl/backends/wayland/window/event/original_processor.hpp>
#include <awl/backends/wayland/window/event/processor.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/close_signal.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show_callback.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
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
		fcppt::log::_
			<<
			FCPPT_TEXT("Got resize event ")
			<<
			size
	);

	data.resize_signal_(
		awl::window::event::resize{
			size
		}
	);
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

awl::backends::wayland::window::event::original_processor::original_processor(
	fcppt::log::object &_log,
	awl::backends::wayland::window::shell_surface &_shell_surface
)
:
	awl::backends::wayland::window::event::processor(),
	close_signal_{
		awl::window::event::close_signal::combiner_function{
			[](
				bool const _arg1,
				bool const _arg2
			)
			{
				return
					_arg1
					&&
					_arg2;
			}
		},
		awl::window::event::close_signal::initial_value{
			true
		}
	},
	destroy_signal_{},
	hide_signal_{},
	show_signal_{},
	data_{
		_log
	}
{
	::wl_shell_surface_add_listener(
		_shell_surface.get(),
		&shell_surface_listener,
		&data_
	);
}

awl::backends::wayland::window::event::original_processor::~original_processor()
{
}

fcppt::signal::auto_connection
awl::backends::wayland::window::event::original_processor::close_callback(
	awl::window::event::close_callback const &_callback
)
{
	return
		close_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::wayland::window::event::original_processor::destroy_callback(
	awl::window::event::destroy_callback const &_callback
)
{
	return
		destroy_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::wayland::window::event::original_processor::hide_callback(
	awl::window::event::hide_callback const &_callback
)
{
	return
		hide_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::wayland::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		data_.resize_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::wayland::window::event::original_processor::show_callback(
	awl::window::event::show_callback const &_callback
)
{
	return
		show_signal_.connect(
			_callback
		);
}
