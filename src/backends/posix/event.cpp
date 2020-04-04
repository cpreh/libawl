#include <awl/backends/posix/event.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/event/base.hpp>


awl::backends::posix::event::event(
	awl::backends::posix::fd const _fd
)
:
	awl::event::base(),
	fd_{
		_fd
	}
{
}


awl::backends::posix::event::~event()
= default;

awl::backends::posix::fd
awl::backends::posix::event::fd() const
{
	return
		fd_;
}
