#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_SCOPED_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_SCOPED_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
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
		awl::backends::windows::system::event::original_processor &,
		awl::backends::windows::window::object &,
		awl::backends::windows::window::event::processor &
	);

	~scoped_processor();
private:
	awl::backends::windows::system::event::original_processor &system_processor_;

	awl::backends::windows::window::object &window_;
};

}
}
}
}
}

#endif
