#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/event_fwd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/backends/posix/processor_unique_ptr.hpp>
#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/function.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/object_fwd.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_std_hash.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


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

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::x11::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_processor(
		awl::backends::x11::display &
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
	awl::system::event::result
	poll_result()
	override;

	AWL_DETAIL_SYMBOL
	void
	quit(
		awl::main::exit_code
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::x11::system::event::opcode const &,
		awl::backends::x11::system::event::type const &,
		awl::backends::x11::system::event::callback const &
	)
	override;

	awl::backends::posix::processor &
	fd_processor()
	override;

	void
	add_window_processor(
		awl::backends::x11::window::object &,
		awl::backends::x11::window::event::processor &
	);

	void
	remove_window_processor(
		awl::backends::x11::window::object const &
	);
private:
	awl::main::optional_exit_code
	process(
		awl::backends::posix::optional_duration const &
	);

	void
	process_pending(
		awl::backends::posix::event const &
	);

	void
	process_event(
		awl::backends::x11::system::event::object const &
	);

	awl::backends::x11::display &display_;

	awl::backends::posix::processor_unique_ptr const fd_processor_;

	typedef
	fcppt::signal::object<
		awl::backends::x11::system::event::function
	>
	signal;

	typedef
	std::map<
		awl::backends::x11::system::event::map_key,
		signal
	>
	event_signal_map;

	event_signal_map signals_;

	fcppt::signal::auto_connection const fd_connection_;

	awl::main::optional_exit_code exit_code_;

	typedef
	fcppt::reference<
		awl::backends::x11::window::event::processor
	>
	window_event_processor_ref;

	typedef
	std::unordered_map<
		Window,
		window_event_processor_ref
	>
	window_processor_map;

	window_processor_map window_processors_;
};

}
}
}
}
}

#endif
