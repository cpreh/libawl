#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_GLOBAL_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_GLOBAL_DATA_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/optional_compositor.hpp>
#include <awl/backends/wayland/optional_shell.hpp>
#include <awl/backends/wayland/optional_shm.hpp>
#include <awl/backends/wayland/system/event/global_data_fwd.hpp>
#include <awl/backends/wayland/system/seat/set.hpp>
#include <awl/event/container.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

struct global_data
{
	FCPPT_NONCOPYABLE(
		global_data
	);
public:
	global_data(
		fcppt::log::object &,
		awl::backends::wayland::display_reference
	);

	~global_data();

	fcppt::log::object &log_;

	awl::backends::wayland::display_reference const display_;

	awl::backends::wayland::optional_compositor compositor_;

	awl::backends::wayland::optional_shell shell_;

	awl::backends::wayland::optional_shm shm_;

	awl::backends::wayland::system::seat::set seats_;

	awl::main::optional_exit_code exit_code_;

	awl::event::container last_events_;
};

}
}
}
}
}

#endif
