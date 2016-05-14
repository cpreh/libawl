#include <awl/backends/wayland/system/event/global_data.hpp>
#include <fcppt/signal/object_impl.hpp>


awl::backends::wayland::system::event::global_data::global_data()
:
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
