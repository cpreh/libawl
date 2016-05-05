#include <awl/backends/wayland/system/event/global_data.hpp>


awl::backends::wayland::system::event::global_data::global_data()
:
	compositor_{},
	shell_{},
	shm_{},
	exit_code_{}
{
}
