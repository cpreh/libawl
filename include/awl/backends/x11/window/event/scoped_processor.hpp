#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SCOPED_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SCOPED_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

class scoped_processor
{
	FCPPT_NONCOPYABLE(
		scoped_processor
	);
public:
	scoped_processor(
		awl::backends::x11::system::event::original_processor &,
		awl::backends::x11::window::object &,
		awl::backends::x11::window::event::processor &
	);

	~scoped_processor();
private:
	awl::backends::x11::system::event::original_processor &system_processor_;

	awl::backends::x11::window::object &window_;
};

}
}
}
}
}

#endif
