#include <awl/backends/linux/epoll/original_processor.hpp>
#include <awl/backends/linux/epoll/set.hpp>
#include <awl/backends/linux/eventfd/posted.hpp>
#include <awl/backends/linux/timerfd/timer.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <awl/backends/posix/posted.hpp>
#include <awl/backends/posix/posted_unique_ptr.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/posix/timer.hpp>
#include <awl/backends/posix/timer_delay.hpp>
#include <awl/backends/posix/timer_period.hpp>
#include <awl/backends/posix/timer_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
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


awl::backends::linux::epoll::original_processor::original_processor()
:
	awl::backends::posix::processor(),
	fd_set_(),
	fd_signals_()
{
}

awl::backends::linux::epoll::original_processor::~original_processor()
{
}

fcppt::signal::auto_connection
awl::backends::linux::epoll::original_processor::register_fd_callback(
	awl::backends::posix::fd const &_fd,
	awl::backends::posix::callback const &_callback
)
{
	fcppt::container::get_or_insert_result<
		fd_signal_map::mapped_type &
	> const result(
		fcppt::container::get_or_insert_with_result(
			fd_signals_,
			_fd,
			[](
				awl::backends::posix::fd const &
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
					&awl::backends::linux::epoll::original_processor::unregister_fd_signal,
					this,
					_fd
				)
			}
		);
}

awl::backends::posix::posted_unique_ptr
awl::backends::linux::epoll::original_processor::post(
	awl::backends::posix::callback const &_callback
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::backends::posix::posted
		>(
			fcppt::make_unique_ptr<
				awl::backends::linux::eventfd::posted
			>(
				*this,
				_callback
			)
		);
}

awl::backends::posix::timer_unique_ptr
awl::backends::linux::epoll::original_processor::create_timer(
	awl::backends::posix::callback const &_callback,
	awl::backends::posix::timer_delay const _delay,
	awl::backends::posix::timer_period const _period
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::backends::posix::timer
		>(
			fcppt::make_unique_ptr<
				awl::backends::linux::timerfd::timer
			>(
				*this,
				_callback,
				_delay,
				_period
			)
		);
}

void
awl::backends::linux::epoll::original_processor::poll(
	awl::backends::posix::optional_duration const &_duration
)
{
	for(
		awl::backends::posix::fd const &fd
		:
		fd_set_.epoll(
			_duration
		)
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
					awl::backends::posix::event()
				);
			}
		);
}

void
awl::backends::linux::epoll::original_processor::unregister_fd_signal(
	awl::backends::posix::fd const &_fd
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
