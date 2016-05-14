
#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/linux/fd/event_fwd.hpp>
#include <awl/backends/linux/fd/optional_duration_fwd.hpp>
#include <awl/backends/linux/fd/original_processor.hpp>
#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/registry.hpp>
#include <awl/backends/wayland/seat_set.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/shm_fwd.hpp>
#include <awl/backends/wayland/system/event/global_data.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/backends/wayland/system/event/seat_callback.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <awl/main/optional_exit_code_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


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

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::wayland::system::event::processor,
	public awl::backends::linux::fd::original_processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_processor(
		awl::backends::wayland::display &
	);

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::main::optional_exit_code
	poll()
	override;

	AWL_DETAIL_SYMBOL
	awl::main::optional_exit_code
	next()
	override;

	AWL_DETAIL_SYMBOL
	void
	quit(
		awl::main::exit_code
	)
	override;

	awl::backends::wayland::compositor const &
	compositor() const
	override;

	awl::backends::wayland::shell const &
	shell() const
	override;

	awl::backends::wayland::shm const &
	shm() const
	override;

	awl::backends::wayland::seat_set const &
	seats() const
	override;

	fcppt::signal::auto_connection
	seat_callback(
		awl::backends::wayland::system::event::seat_callback const &
	)
	override;
private:
	awl::main::optional_exit_code
	process(
		awl::backends::linux::fd::optional_duration const &
	);

	void
	process_pending(
		awl::backends::linux::fd::event const &
	);

	awl::backends::wayland::display &display_;

	awl::backends::wayland::registry registry_;

	awl::backends::wayland::system::event::global_data global_data_;

	fcppt::signal::auto_connection const fd_connection_;
};

}
}
}
}
}

#endif
