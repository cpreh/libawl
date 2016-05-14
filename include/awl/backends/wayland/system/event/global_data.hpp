#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_GLOBAL_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_GLOBAL_DATA_HPP_INCLUDED

#include <awl/backends/wayland/optional_compositor.hpp>
#include <awl/backends/wayland/optional_shell.hpp>
#include <awl/backends/wayland/optional_shm.hpp>
#include <awl/backends/wayland/seat_set.hpp>
#include <awl/backends/wayland/system/event/global_data_fwd.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/noncopyable.hpp>


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
	global_data();

	~global_data();

	awl::backends::wayland::optional_compositor compositor_;

	awl::backends::wayland::optional_shell shell_;

	awl::backends::wayland::optional_shm shm_;

	awl::backends::wayland::seat_set seats_;

	awl::main::optional_exit_code exit_code_;

};

}
}
}
}
}

#endif
