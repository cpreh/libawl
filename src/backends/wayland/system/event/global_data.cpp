#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/global_data.hpp>
#include <awl/event/base.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/log/object_fwd.hpp>


awl::backends::wayland::system::event::global_data::global_data(
	fcppt::reference<
		fcppt::log::object
	> const _log,
	awl::backends::wayland::display_reference const _display
)
:
	log_{
		_log
	},
	display_{
		_display
	},
	compositor_{},
	shell_{},
	shm_{},
	seats_{},
	exit_code_{},
	last_events_{}
{
}

awl::backends::wayland::system::event::global_data::~global_data()
= default;
