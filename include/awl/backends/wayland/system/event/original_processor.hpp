
#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/backends/posix/processor_unique_ptr.hpp>
#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/registry.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/shm_fwd.hpp>
#include <awl/backends/wayland/system/event/global_data.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/backends/wayland/system/seat/set.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/container.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/log/object_fwd.hpp>


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

class AWL_DETAIL_CLASS_SYMBOL original_processor
:
	public awl::backends::wayland::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor(
		fcppt::log::object &,
		awl::backends::wayland::display &
	);

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::result
	poll()
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::result
	next()
	override;

	AWL_DETAIL_SYMBOL
	void
	quit(
		awl::main::exit_code
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::timer::unique_ptr
	create_timer(
		awl::timer::setting const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::event::container_reference
	events()
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::compositor const &
	compositor() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::shell const &
	shell() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::shm const &
	shm() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::system::seat::set const &
	seats() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::posix::processor &
	fd_processor()
	override;
private:
	awl::system::event::result
	process(
		awl::backends::posix::optional_duration const &
	);

	awl::event::container
	process_fds(
		awl::backends::posix::optional_duration const &
	);

	awl::event::container
	process_pending();

	awl::backends::wayland::display &display_;

	awl::backends::posix::processor_unique_ptr const fd_processor_;

	awl::backends::wayland::registry registry_;

	awl::backends::wayland::system::event::global_data global_data_;

	awl::backends::posix::fd const fd_;
};

}
}
}
}
}

#endif
