#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/system/event/callback.hpp>
#include <awl/backends/windows/system/event/handle_callback.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


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
		awl::backends::windows::message_type,
		awl::backends::windows::system::event::callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	register_handle_callback(
		awl::backends::windows::system::event::handle_callback const &
	) = 0;

	virtual
	awl::backends::windows::system::event::handle_unique_ptr
	create_event_handle() = 0;

	virtual
	awl::backends::windows::message_type
	allocate_user_message() = 0;

	virtual
	void
	free_user_message(
		awl::backends::windows::message_type
	) = 0;
};

}
}
}
}
}

#endif
