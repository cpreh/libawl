#ifndef AWL_BACKENDS_WAYLAND_WINDOW_EVENT_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_EVENT_DATA_HPP_INCLUDED

#include <awl/backends/wayland/window/event/data_fwd.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/reference.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/log/object_reference.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace window
{
namespace event
{

class data
{
	FCPPT_NONMOVABLE(
		data
	);
public:
	data(
		fcppt::log::object_reference,
		awl::window::reference,
		awl::event::container_reference
	);

	~data(); // NOLINT(performance-trivially-destructible)

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	fcppt::log::object_reference const log_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::window::reference const reference_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::event::container_reference const events_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::window::optional_dim size_;

};

}
}
}
}
}

#endif
