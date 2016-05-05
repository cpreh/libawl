#ifndef AWL_BACKENDS_WAYLAND_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/wayland/window/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/processor.hpp>
#include <fcppt/noncopyable.hpp>


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

class AWL_CLASS_SYMBOL processor
:
	public awl::window::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_DETAIL_SYMBOL
	processor();
public:
	AWL_DETAIL_SYMBOL
	~processor()
	override;
};

}
}
}
}
}

#endif
