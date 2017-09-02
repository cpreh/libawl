#include <awl/backends/wayland/window/event/data.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/window/reference.hpp>
#include <fcppt/log/object_fwd.hpp>


awl::backends::wayland::window::event::data::data(
	fcppt::log::object &_log,
	awl::window::reference const _reference,
	awl::event::container_reference const _events
)
:
	log_{
		_log
	},
	reference_{
		_reference
	},
	events_{
		_events
	},
	size_{}
{
}

awl::backends::wayland::window::event::data::~data()
{
}
