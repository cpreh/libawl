#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/linux/fd/event_fwd.hpp>
#include <awl/backends/linux/fd/original_processor.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/function.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/object_fwd.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <awl/system/event/quit_signal.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_std_hash.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
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
	public awl::backends::x11::system::event::processor,
	public awl::backends::linux::fd::original_processor
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
	awl::window::event::processor_unique_ptr
	create_window_processor(
		awl::window::object &
	)
	override;

	AWL_DETAIL_SYMBOL
	void
	quit(
		awl::main::exit_code
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	quit_callback(
		awl::system::event::quit_callback const &
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
private:
	void
	process_pending(
		awl::backends::linux::fd::event const &
	);

	void
	process_event(
		awl::backends::x11::system::event::object const &
	);

	awl::backends::x11::display &display_;

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

	awl::system::event::quit_signal quit_signal_;

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
