#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/match.hpp>
#include <awl/event/base_fwd.hpp>
#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/optional/maybe.hpp>


bool
awl::backends::posix::match(
	awl::event::base const &_event,
	awl::backends::posix::fd const _fd
)
{
	return
		fcppt::optional::maybe(
			fcppt::cast::dynamic<
				awl::backends::posix::event const
			>(
				_event
			),
			fcppt::const_(
				false
			),
			[
				_fd
			](
				fcppt::reference<
					awl::backends::posix::event const
				> const _posix_event
			)
			{
				return
					_posix_event.get().fd()
					==
					_fd;
			}
		);
}
