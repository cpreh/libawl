#include <awl/backends/wayland/window/event/data.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/signal/object_impl.hpp>


awl::backends::wayland::window::event::data::data(
	fcppt::log::object &_log
)
:
	log_{
		_log
	},
	resize_signal_()
{
}

awl::backends::wayland::window::event::data::~data()
{
}
