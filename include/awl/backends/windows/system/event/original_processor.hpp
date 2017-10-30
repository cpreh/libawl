#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/message_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/event/optional_base_unique_ptr_fwd.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <awl/timer/reference.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/function_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <vector>
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

class AWL_DETAIL_CLASS_SYMBOL original_processor
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
	awl::backends::windows::system::event::handle_unique_ptr
	create_event_handle()
	override;

	AWL_DETAIL_SYMBOL
	awl::event::container_reference
	next_events();
private:
	typedef
	fcppt::function<
		DWORD (
			DWORD,
			HANDLE const *,
			BOOL,
			DWORD
		)
	>
	handle_function;

	FCPPT_MAKE_STRONG_TYPEDEF(
		DWORD,
		timeout
	);

	awl::system::event::result
	process(
		handle_function const &,
		timeout
	);

	awl::event::container
	poll_messages();

	awl::event::optional_base_unique_ptr
	process_system_message(
		awl::backends::windows::message const &
	);

	awl::event::base_unique_ptr
	make_message(
		awl::backends::windows::message const &
	);

	awl::system::event::result
	generic_multiple_wait(
		handle_function const &,
		timeout
	);

	awl::event::base_unique_ptr
	handle_event(
		DWORD
	);

	void
	remove_handle(
		HANDLE
	);

	typedef
	std::vector<
		HANDLE
	>
	handle_vector;

	handle_vector handles_;

	typedef
	std::unordered_map<
		HANDLE,
		awl::timer::reference
	>
	timer_map;

	timer_map timers_;

	awl::main::optional_exit_code exit_code_;

	awl::event::container next_events_;
};

}
}
}
}
}

#endif
