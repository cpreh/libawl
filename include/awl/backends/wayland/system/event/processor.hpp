#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/seat_set_fwd.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/shm_fwd.hpp>
#include <awl/backends/wayland/system/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor.hpp>
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
	awl::backends::wayland::compositor const &
	compositor() const = 0;

	virtual
	awl::backends::wayland::shell const &
	shell() const = 0;

	virtual
	awl::backends::wayland::shm const &
	shm() const = 0;

	virtual
	awl::backends::wayland::seat_set const &
	seats() const = 0;
};

}
}
}
}
}

#endif
