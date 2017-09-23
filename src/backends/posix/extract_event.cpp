#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/extract_event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/event/map_concat.hpp>
#include <awl/event/variant.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::event::container
awl::backends::posix::extract_event(
	awl::event::container &&_events,
	awl::backends::posix::fd const _fd,
	fcppt::function<
		awl::event::container ()
	> const _function
)
{
	return
		awl::event::map_concat<
			awl::event::base_unique_ptr
		>(
			std::move(
				_events
			),
			[
				_fd,
				&_function
			](
				awl::event::base_unique_ptr &&_event
			)
			{
				return
					fcppt::optional::maybe(
						fcppt::cast::dynamic<
							awl::backends::posix::event const
						>(
							*_event
						),
						[
							&_event
						]{
							return
								awl::event::variant<
									awl::event::base_unique_ptr
								>(
									std::move(
										_event
									)
								);
						},
						[
							_fd,
							&_function,
							&_event
						](
							fcppt::reference<
								awl::backends::posix::event const
							> const _posix_event
						)
						{
							return
								_posix_event.get().fd()
								==
								_fd
								?
									awl::event::variant<
										awl::event::base_unique_ptr
									>(
										_function()
									)
								:
									awl::event::variant<
										awl::event::base_unique_ptr
									>(
										fcppt::unique_ptr_to_base<
											awl::event::base
										>(
											std::move(
												_event
											)
										)
									)
								;
						}
					);
			}
		);
}
