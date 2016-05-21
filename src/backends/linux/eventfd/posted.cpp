#include <awl/backends/linux/eventfd/object.hpp>
#include <awl/backends/linux/eventfd/posted.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/event_fwd.hpp>
#include <awl/backends/posix/posted.hpp>
#include <awl/backends/posix/processor.hpp>


awl::backends::linux::eventfd::posted::posted(
	awl::backends::posix::processor &_processor,
	awl::backends::posix::callback const &_callback
)
:
	awl::backends::posix::posted(),
	fd_{},
	fd_connection_{
		_processor.register_fd_callback(
			fd_.get(),
			awl::backends::posix::callback{
				[
					this,
					_callback
				](
					awl::backends::posix::event const &_event
				)
				{
					fd_.read();

					_callback(
						_event
					);
				}
			}
		)
	}
{
	fd_.write();
}

awl::backends::linux::eventfd::posted::~posted()
{
}
