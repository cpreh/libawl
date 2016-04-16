#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/event/object_fwd.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/processor_fwd.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL processor
:
	public awl::system::event::processor
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

	virtual
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::x11::system::event::opcode const &,
		awl::backends::x11::system::event::type const &,
		awl::backends::x11::system::event::callback const &
	) = 0;

	virtual
	void
	process(
		awl::backends::x11::event::object const &
	) = 0;
};

}
}
}
}
}

#endif
