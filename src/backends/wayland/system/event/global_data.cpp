#include <awl/backends/wayland/system/event/global_data.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/signal/object_impl.hpp>


awl::backends::wayland::system::event::global_data::global_data(
	fcppt::log::object &_log
)
:
	log_{
		_log
	},
	compositor_{},
	shell_{},
	shm_{},
	seats_{},
	exit_code_{}
{
}

awl::backends::wayland::system::event::global_data::~global_data()
{
}
