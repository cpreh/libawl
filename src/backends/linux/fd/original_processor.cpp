#include <awl/backends/linux/fd/callback.hpp>
#include <awl/backends/linux/fd/duration.hpp>
#include <awl/backends/linux/fd/event.hpp>
#include <awl/backends/linux/fd/function.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/object_vector.hpp>
#include <awl/backends/linux/fd/optional_duration.hpp>
#include <awl/backends/linux/fd/original_processor.hpp>
#include <awl/backends/linux/fd/processor.hpp>
#include <awl/backends/linux/fd/epoll/set.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/get_or_insert_result.hpp>
#include <fcppt/container/get_or_insert_with_result.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/unregister/base_impl.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


awl::backends::linux::fd::original_processor::original_processor()
:
	awl::backends::linux::fd::original_processor::processor(),
	fd_set_(),
	fd_signals_()
{
}

awl::backends::linux::fd::original_processor::~original_processor()
{
}

fcppt::signal::auto_connection
awl::backends::linux::fd::original_processor::register_fd_callback(
	awl::backends::linux::fd::object const &_fd,
	awl::backends::linux::fd::callback const &_callback
)
{
	fcppt::container::get_or_insert_result<
		fd_signal_map::mapped_type &
	> const result(
		fcppt::container::get_or_insert_with_result(
			fd_signals_,
			_fd,
			[](
				awl::backends::linux::fd::object const &
			)
			{
				return
					fd_signal();
			}
		)
	);

	if(
		result.inserted()
	)
		fd_set_.add(
			_fd
		);

	return
		result.element().connect(
			_callback,
			fcppt::signal::unregister::function{
				std::bind(
					&awl::backends::linux::fd::original_processor::unregister_fd_signal,
					this,
					_fd
				)
			}
		);
}

bool
awl::backends::linux::fd::original_processor::epoll(
	awl::backends::linux::fd::optional_duration const &_duration
)
{
	awl::backends::linux::fd::object_vector const &ready_fds(
		fd_set_.epoll(
			_duration
		)
	);

	for(
		awl::backends::linux::fd::object const &fd
		:
		ready_fds
	)
		fcppt::optional::maybe_void(
			fcppt::container::find_opt_mapped(
				fd_signals_,
				fd
			),
			[](
				fcppt::reference<
					fd_signal
				> const _signal
			)
			{
				_signal.get()(
					awl::backends::linux::fd::event()
				);
			}
		);

	return
		!ready_fds.empty();
}

void
awl::backends::linux::fd::original_processor::unregister_fd_signal(
	awl::backends::linux::fd::object const &_fd
)
{
	fd_signal_map::iterator const it(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			fcppt::container::find_opt_iterator(
				fd_signals_,
				_fd
			)
		)
	);

	fd_set_.remove(
		_fd
	);

	if(
		it->second.empty()
	)
		fd_signals_.erase(
			it
		);
}
