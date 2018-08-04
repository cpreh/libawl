#include <awl/backends/linux/epoll/original_processor.hpp>
#include <awl/backends/linux/timer/object.hpp>
#include <awl/backends/linux/timer/reference.hpp>
#include <awl/backends/linux/timer/unique_ptr.hpp>
#include <awl/backends/linux/timerfd/object.hpp>
#include <awl/backends/linux/timerfd/unique_ptr.hpp>
#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/event/base.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/event/make_connection.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/insert.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::linux::epoll::original_processor::original_processor()
:
	awl::backends::posix::processor{},
	fd_set_{},
	timers_{}
{
}

awl::backends::linux::epoll::original_processor::~original_processor()
{
}

awl::event::connection_unique_ptr
awl::backends::linux::epoll::original_processor::register_fd(
	awl::backends::posix::fd const &_fd
)
{
	awl::event::connection_unique_ptr result{
		awl::event::make_connection(
			awl::event::connection_function{
				[
					this,
					_fd
				]{
					fd_set_.remove(
						_fd
					);

					timers_.erase(
						_fd
					);
				}
			}
		)
	};

	fd_set_.add(
		_fd
	);

	return
		result;
}

awl::event::container
awl::backends::linux::epoll::original_processor::poll(
	awl::backends::posix::optional_duration const &_duration
)
{
	return
		fcppt::algorithm::map<
			awl::event::container
		>(
			fd_set_.epoll(
				_duration
			),
			[
				this
			](
				awl::backends::posix::fd const _fd
			)
			{
				return
					fcppt::optional::maybe(
						fcppt::container::find_opt_mapped(
							timers_,
							_fd
						),
						[
							_fd
						]{
							return
								fcppt::unique_ptr_to_base<
									awl::event::base
								>(
									fcppt::make_unique_ptr<
										awl::backends::posix::event
									>(
										_fd
									)
								);
						},
						[](
							fcppt::reference<
								awl::backends::linux::timer::reference
							> const _timer
						)
						{
							// TODO: Should we include this number in the timer event?
							_timer.get().get().read();

							return
								fcppt::unique_ptr_to_base<
									awl::event::base
								>(
									fcppt::make_unique_ptr<
										awl::timer::event
									>(
										fcppt::reference_to_base<
											awl::timer::object
										>(
											_timer.get()
										)
									)
								);
						}
					);
			}
		);
}

awl::timer::unique_ptr
awl::backends::linux::epoll::original_processor::create_timer(
	awl::timer::setting const &_setting
)
{
	awl::backends::linux::timerfd::unique_ptr object{
		fcppt::make_unique_ptr<
			awl::backends::linux::timerfd::object
		>()
	};

	object->set_time(
		_setting
	);

	awl::event::connection_unique_ptr connection{
		this->register_fd(
			object->get()
		)
	};

	awl::backends::linux::timer::unique_ptr result{
		fcppt::make_unique_ptr<
			awl::backends::linux::timer::object
		>(
			std::move(
				object
			),
			std::move(
				connection
			)
		)
	};

	FCPPT_ASSERT_ERROR(
		fcppt::container::insert(
			timers_,
			std::make_pair(
				result->fd(),
				fcppt::make_ref(
					*result
				)
			)
		)
	);

	return
		fcppt::unique_ptr_to_base<
			awl::timer::object
		>(
			std::move(
				result
			)
		);
}
