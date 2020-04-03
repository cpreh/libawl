#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/posix/processor_base.hpp>
#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/shm_fwd.hpp>
#include <awl/backends/wayland/system/event/processor_fwd.hpp>
#include <awl/backends/wayland/system/seat/set.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/system/event/processor.hpp>
#include <fcppt/nonmovable.hpp>


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

	// TODO(philipp): Should this be here?
	[[nodiscard]]
	virtual
	awl::event::container_reference
	events() = 0;

	[[nodiscard]]
	virtual
	awl::backends::wayland::compositor const &
	compositor() const = 0;

	[[nodiscard]]
	virtual
	awl::backends::wayland::shell const &
	shell() const = 0;

	[[nodiscard]]
	virtual
	awl::backends::wayland::shm const &
	shm() const = 0;

	[[nodiscard]]
	virtual
	awl::backends::wayland::system::seat::set const &
	seats() const = 0;
};

}
}
}
}
}

#endif
