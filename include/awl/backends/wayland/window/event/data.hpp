#ifndef AWL_BACKENDS_WAYLAND_WINDOW_EVENT_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_EVENT_DATA_HPP_INCLUDED

#include <awl/backends/wayland/window/event/data_fwd.hpp>
#include <awl/window/event/resize_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/object_decl.hpp>


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
	data();

	~data();

	awl::window::event::resize_signal resize_signal_;
};

}
}
}
}
}

#endif
