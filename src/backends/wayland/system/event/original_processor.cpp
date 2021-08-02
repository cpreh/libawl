#include <awl/exception.hpp>
#include <awl/backends/posix/create_processor.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/extract_event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/wayland/compositor.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_dispatch_pending.hpp>
#include <awl/backends/wayland/display_flush.hpp>
#include <awl/backends/wayland/display_prepare_read.hpp>
#include <awl/backends/wayland/display_read_events.hpp>
#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/display_roundtrip.hpp>
#include <awl/backends/wayland/optional_compositor.hpp>
#include <awl/backends/wayland/optional_shell.hpp>
#include <awl/backends/wayland/optional_shm.hpp>
#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/seat.hpp>
#include <awl/backends/wayland/shell.hpp>
#include <awl/backends/wayland/shm.hpp>
#include <awl/backends/wayland/system/event/global_data.hpp>
#include <awl/backends/wayland/system/event/original_processor.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/backends/wayland/system/event/seat_added.hpp>
#include <awl/backends/wayland/system/event/seat_removed.hpp>
#include <awl/backends/wayland/system/seat/object.hpp>
#include <awl/backends/wayland/system/seat/set.hpp>
#include <awl/event/base.hpp>
#include <awl/event/container.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/event/map_concat.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/exit_failure.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move_clear.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/object_reference.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <cstdint>
#include <string>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

void
registry_add(
	void *const _data,
	wl_registry *const _registry,
	std::uint32_t const _name,
	char const *const _interface,
	std::uint32_t // version
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
		data.log_.get(),
		fcppt::log::out
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
	)

	if(
		interface
		==
		"wl_compositor"
	)
	{
		data.compositor_ =
			awl::backends::wayland::optional_compositor{
				awl::backends::wayland::compositor{
					_registry,
					name
				}
			};
	}
	else if(
		interface
		==
		"wl_shell"
	)
	{
		data.shell_ =
			awl::backends::wayland::optional_shell{
				awl::backends::wayland::shell{
					_registry,
					name
				}
			};
	}
	else if(
		interface
		==
		"wl_shm"
	)
	{
		data.shm_ =
			awl::backends::wayland::optional_shm{
				awl::backends::wayland::shm{
					_registry,
					name
				}
			};
	}
	else if(
		interface
		==
		"wl_seat"
	)
	{
		std::pair<
			awl::backends::wayland::system::seat::set::iterator,
			bool
		> const result{
			data.seats_.insert(
				fcppt::make_shared_ptr<
					awl::backends::wayland::system::seat::object
				>(
					awl::backends::wayland::seat{
						_registry,
						name
					},
					data.display_,
					fcppt::make_ref(
						data.last_events_
					)
				)
			)
		};

		if(
			!result.second
		)
		{
			throw
				awl::exception{
					FCPPT_TEXT("Double insert of wayland seat")
				};
		}

		(*result.first)->init_ptr();

		data.last_events_.push_back(
			fcppt::unique_ptr_to_base<
				awl::event::base
			>(
				fcppt::make_unique_ptr<
					awl::backends::wayland::system::event::seat_added
				>(
					data.display_,
					*result.first
				)
			)
		);
	}
}

void
registry_remove(
	void *const _data,
	wl_registry *,
	std::uint32_t const _name
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

	fcppt::optional::maybe_void(
		fcppt::container::find_opt_iterator(
			data.seats_,
			name
		),
		[
			&data
		](
			awl::backends::wayland::system::seat::set::iterator const _it
		)
		{
			data.last_events_.push_back(
				fcppt::unique_ptr_to_base<
					awl::event::base
				>(
					fcppt::make_unique_ptr<
						awl::backends::wayland::system::event::seat_removed
					>(
						data.display_,
						*_it
					)
				)
			);

			data.seats_.erase(
				_it
			);
		}
	);
}

wl_registry_listener const registry_listener{
	registry_add,
	registry_remove
};

}

awl::backends::wayland::system::event::original_processor::original_processor(
	fcppt::log::object_reference const _log,
	awl::backends::wayland::display_reference const _display
)
:
	awl::backends::wayland::system::event::processor(),
	display_{
		_display
	},
	fd_processor_{
		awl::backends::posix::create_processor()
	},
	registry_{
		_display.get()
	},
	global_data_{
		_log,
		_display
	},
	fd_{
		::wl_display_get_fd(
			_display.get().get()
		)
	}
{
	::wl_registry_add_listener(
		registry_.get(),
		&registry_listener,
		&global_data_
	);

	awl::backends::wayland::display_roundtrip(
		display_.get()
	);
}

awl::backends::wayland::system::event::original_processor::~original_processor()
= default;

awl::system::event::result
awl::backends::wayland::system::event::original_processor::poll()
{
	return
		this->process(
			awl::backends::posix::optional_duration{
				// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
				awl::backends::posix::duration{
					0
				}
			}
		);
}

awl::system::event::result
awl::backends::wayland::system::event::original_processor::next()
{
	return
		this->process(
			awl::backends::posix::optional_duration()
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

awl::timer::unique_ptr
awl::backends::wayland::system::event::original_processor::create_timer(
	awl::timer::setting const &_setting
)
{
	return
		fd_processor_->create_timer(
			_setting
		);
}

awl::event::container_reference
awl::backends::wayland::system::event::original_processor::events()
{
	return
		fcppt::make_ref(
			global_data_.last_events_
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
		global_data_.seats_;
}

awl::backends::posix::processor &
awl::backends::wayland::system::event::original_processor::fd_processor()
{
	return
		*fd_processor_;
}

awl::system::event::result
awl::backends::wayland::system::event::original_processor::process(
	awl::backends::posix::optional_duration const &_duration
)
{
	return
		fcppt::optional::maybe(
			global_data_.exit_code_,
			[
				this,
				&_duration
			]{
				return
					awl::system::event::result{
						this->process_fds(
							_duration
						)
					};
			},
			[](
				awl::main::exit_code const _code
			)
			{
				return
					awl::system::event::result{
						_code
					};
			}
		);
}

awl::event::container
awl::backends::wayland::system::event::original_processor::process_fds(
	awl::backends::posix::optional_duration const &_duration
)
{
	awl::backends::wayland::display_flush(
		display_.get()
	);

	return
		awl::backends::posix::extract_event(
			fd_processor_->poll(
				_duration
			),
			fd_,
			fcppt::function<
				awl::event::container ()
			>{
				[
					this
				]{
					return
						this->process_pending();
				}
			}
		);
}

awl::event::container
awl::backends::wayland::system::event::original_processor::process_pending()
{
	while(
		!awl::backends::wayland::display_prepare_read(
			display_.get()
		)
	)
	{
		awl::backends::wayland::display_dispatch_pending(
			display_.get()
		);
	}

	awl::backends::wayland::display_read_events(
		display_.get()
	);

	awl::backends::wayland::display_dispatch_pending(
		display_.get()
	);

	return
		fcppt::move_clear(
			global_data_.last_events_
		);
}
