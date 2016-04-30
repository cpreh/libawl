#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


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
	virtual
	~processor()
	override;

	virtual
	awl::backends::x11::window::object &
	x11_window() const = 0;

	virtual
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::x11::window::event::type,
		awl::backends::x11::window::event::callback const &
	) = 0;

	virtual
	void
	process(
		awl::backends::x11::window::event::object const &
	) = 0;
};

}
}
}
}
}

#endif
