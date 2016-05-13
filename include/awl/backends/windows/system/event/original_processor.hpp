#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/windows/message_fwd.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/callback.hpp>
#include <awl/backends/windows/system/event/handle_callback.hpp>
#include <awl/backends/windows/system/event/handle_function.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_decl.hpp>
#include <fcppt/strong_typedef_std_hash.hpp>
#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::windows::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor();

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

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::windows::message_type,
		awl::backends::windows::system::event::callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	register_handle_callback(
		awl::backends::windows::system::event::handle_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::system::event::handle_unique_ptr
	create_event_handle()
	override;

	void
	add_window_processor(
		awl::backends::windows::window::object &,
		awl::backends::windows::window::event::processor &
	);

	void
	remove_window_processor(
		awl::backends::windows::window::object const &
	);
private:
	awl::main::optional_exit_code
	poll_messages();

	awl::main::optional_exit_code
	process_message(
		awl::backends::windows::message const &
	);

	template<
		typename Function
	>
	void
	generic_multiple_wait(
		Function,
		DWORD timeout
	);

	typedef
	fcppt::signal::object<
		awl::backends::windows::system::event::function
	>
	signal_type;

	typedef
	std::unordered_map<
		awl::backends::windows::message_type,
		signal_type
	>
	signal_map;

	signal_map signals_;

	typedef
	fcppt::signal::object<
		awl::backends::windows::system::event::handle_function
	>
	handle_signal;

	handle_signal handle_signal_;

	typedef
	fcppt::container::raw_vector<
		HANDLE
	>
	handle_vector;

	handle_vector handles_;

	typedef
	fcppt::reference<
		awl::backends::windows::window::event::processor
	>
	window_processor_ref;

	typedef
	std::unordered_map<
		HWND,
		window_processor_ref
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
