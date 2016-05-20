#include <awl/exception.hpp>
#include <awl/log.hpp>
#include <awl/backends/linux/fd/callback.hpp>
#include <awl/backends/linux/fd/duration.hpp>
#include <awl/backends/linux/fd/event_fwd.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/optional_duration.hpp>
#include <awl/backends/linux/fd/original_processor.hpp>
#include <awl/backends/wayland/compositor.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_dispatch_pending.hpp>
#include <awl/backends/wayland/display_flush.hpp>
#include <awl/backends/wayland/display_prepare_read.hpp>
#include <awl/backends/wayland/display_read_events.hpp>
#include <awl/backends/wayland/display_roundtrip.hpp>
#include <awl/backends/wayland/optional_compositor.hpp>
#include <awl/backends/wayland/optional_shell.hpp>
#include <awl/backends/wayland/optional_shm.hpp>
#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/shell.hpp>
#include <awl/backends/wayland/shm.hpp>
#include <awl/backends/wayland/system/event/global_data.hpp>
#include <awl/backends/wayland/system/event/original_processor.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/backends/wayland/system/event/seat_callback.hpp>
#include <awl/backends/wayland/system/seat/object.hpp>
#include <awl/backends/wayland/system/seat/set.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/exit_failure.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/const.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <stdint.h>
#include <string>
#include <type_traits>
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


namespace
{

void
registry_add(
	void *const _data,
	wl_registry *const _registry,
	uint32_t const _name,
	char const *const _interface,
	uint32_t // version
)
{
	awl::backends::wayland::system::event::global_data &data(
		*fcppt::cast::from_void_ptr<
			awl::backends::wayland::system::event::global_data *
		>(
			_data
		)
	);

	std::string const interface{
		_interface
	};

	awl::backends::wayland::registry_id const name{
		_name
	};

	FCPPT_LOG_DEBUG(
		awl::log(),
		fcppt::log::_
			<<
			FCPPT_TEXT("Got registry object \"")
			<<
			fcppt::from_std_string(
				interface
			)
			<<
			FCPPT_TEXT("\" with id ")
			<<
			name
	);

	if(
		interface
		==
		"wl_compositor"
	)
		data.compositor_ =
			awl::backends::wayland::optional_compositor{
				awl::backends::wayland::compositor{
					_registry,
					name
				}
			};
	else if(
		interface
		==
		"wl_shell"
	)
		data.shell_ =
			awl::backends::wayland::optional_shell{
				awl::backends::wayland::shell{
					_registry,
					name
				}
			};
	else if(
		interface
		==
		"wl_shm"
	)
		data.shm_ =
			awl::backends::wayland::optional_shm{
				awl::backends::wayland::shm{
					_registry,
					name
				}
			};
	else if(
		interface
		==
		"wl_seat"
	)
		data.seats_.add(
			awl::backends::wayland::system::seat::object{
				awl::backends::wayland::seat{
					_registry,
					name
				}
			}
		);
}

void
registry_remove(
	void *const _data,
	wl_registry *,
	uint32_t const _name
)
{
	awl::backends::wayland::system::event::global_data &data(
		*fcppt::cast::from_void_ptr<
			awl::backends::wayland::system::event::global_data *
		>(
			_data
		)
	);

	awl::backends::wayland::registry_id const name{
		_name
	};

	auto const process_global(
		[
			name,
			&data
		](
			auto &_object
		)
		{
			if(
				fcppt::optional::maybe(
					_object,
					fcppt::const_(
						false
					),
					[
						name
					](
						auto const &_inner
					)
					{
						return
							_inner.name()
							==
							name;
					}
				)
			)
			{
				data.exit_code_ =
					awl::main::optional_exit_code{
						awl::main::exit_failure()
					};

				_object =
					typename
					std::decay<
						decltype(
							_object
						)
					>::type{};
			}
		}
	);

	process_global(
		data.compositor_
	);

	process_global(
		data.shell_
	);

	process_global(
		data.shm_
	);

	data.seats_.remove(
		name
	);
}

wl_registry_listener const registry_listener{
	registry_add,
	registry_remove
};

}

awl::backends::wayland::system::event::original_processor::original_processor(
	awl::backends::wayland::display &_display
)
:
	awl::backends::wayland::system::event::processor(),
	awl::backends::linux::fd::original_processor(),
	display_{
		_display
	},
	registry_{
		_display
	},
	global_data_(),
	fd_connection_{
		this->register_fd_callback(
			awl::backends::linux::fd::object{
				::wl_display_get_fd(
					_display.get()
				)
			},
			awl::backends::linux::fd::callback{
				std::bind(
					&awl::backends::wayland::system::event::original_processor::process_pending,
					this,
					std::placeholders::_1
				)
			}
		)
	}
{
	::wl_registry_add_listener(
		registry_.get(),
		&registry_listener,
		&global_data_
	);

	awl::backends::wayland::display_roundtrip(
		display_
	);

	awl::backends::wayland::display_roundtrip(
		display_
	);
}

awl::backends::wayland::system::event::original_processor::~original_processor()
{
}

awl::main::optional_exit_code
awl::backends::wayland::system::event::original_processor::poll()
{
	return
		this->process(
			awl::backends::linux::fd::optional_duration{
				awl::backends::linux::fd::duration{
					0
				}
			}
		);
}

awl::main::optional_exit_code
awl::backends::wayland::system::event::original_processor::next()
{
	return
		this->process(
			awl::backends::linux::fd::optional_duration()
		);
}

void
awl::backends::wayland::system::event::original_processor::quit(
	awl::main::exit_code const _exit_code
)
{
	global_data_.exit_code_ =
		awl::main::optional_exit_code(
			_exit_code
		);
}

awl::backends::wayland::compositor const &
awl::backends::wayland::system::event::original_processor::compositor() const
{
	return
		fcppt::optional::to_exception(
			global_data_.compositor_,
			[]{
				return
					awl::exception{
						FCPPT_TEXT("Compositor is gone")
					};
			}
		);
}

awl::backends::wayland::shell const &
awl::backends::wayland::system::event::original_processor::shell() const
{
	return
		fcppt::optional::to_exception(
			global_data_.shell_,
			[]{
				return
					awl::exception{
						FCPPT_TEXT("Shell is gone")
					};
			}
		);
}

awl::backends::wayland::shm const &
awl::backends::wayland::system::event::original_processor::shm() const
{
	return
		fcppt::optional::to_exception(
			global_data_.shm_,
			[]{
				return
					awl::exception{
						FCPPT_TEXT("Shm is gone")
					};
			}
		);
}

awl::backends::wayland::system::seat::set const &
awl::backends::wayland::system::event::original_processor::seats() const
{
	return
		global_data_.seats_.get();
}

fcppt::signal::auto_connection
awl::backends::wayland::system::event::original_processor::seat_callback(
	awl::backends::wayland::system::event::seat_callback const &_callback
)
{
	return
		global_data_.seats_.signal().connect(
			_callback
		);
}

awl::main::optional_exit_code
awl::backends::wayland::system::event::original_processor::process(
	awl::backends::linux::fd::optional_duration const &_duration
)
{
	awl::backends::wayland::display_flush(
		display_
	);

	this->epoll(
		_duration
	);

	return
		global_data_.exit_code_;
}

void
awl::backends::wayland::system::event::original_processor::process_pending(
	awl::backends::linux::fd::event const &
)
{
	while(
		!awl::backends::wayland::display_prepare_read(
			display_
		)
	)
		awl::backends::wayland::display_dispatch_pending(
			display_
		);

	awl::backends::wayland::display_read_events(
		display_
	);

	awl::backends::wayland::display_dispatch_pending(
		display_
	);
}
