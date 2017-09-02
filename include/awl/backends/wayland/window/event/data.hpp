#ifndef AWL_BACKENDS_WAYLAND_WINDOW_EVENT_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_EVENT_DATA_HPP_INCLUDED

#include <awl/backends/wayland/window/event/data_fwd.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/reference.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/log/object_fwd.hpp>


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
	FCPPT_NONCOPYABLE(
		data
	);
public:
	data(
		fcppt::log::object &,
		awl::window::reference,
		awl::event::container_reference
	);

	~data();

	fcppt::log::object &log_;

	awl::window::reference const reference_;

	awl::event::container_reference const events_;

	awl::window::optional_dim size_;

};

}
}
}
}
}

#endif
