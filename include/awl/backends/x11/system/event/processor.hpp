#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/posix/processor_base.hpp>
#include <awl/backends/x11/system/event/processor_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor.hpp>
#include <fcppt/nonmovable.hpp>


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

// NOLINTNEXTLINE(fuchsia-multiple-inheritance)
class AWL_DETAIL_CLASS_SYMBOL processor
:
	public awl::system::event::processor,
	public awl::backends::posix::processor_base
{
	FCPPT_NONMOVABLE(
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
