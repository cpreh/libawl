#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_HANDLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_HANDLE_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_holder_unique_ptr.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


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

class AWL_DETAIL_CLASS_SYMBOL original_handle
:
	public awl::backends::windows::system::event::handle
{
	FCPPT_NONCOPYABLE(
		original_handle
	);
public:
	AWL_DETAIL_SYMBOL
	original_handle(
		awl::backends::windows::system::event::handle_holder_unique_ptr &&,
		awl::event::connection_unique_ptr &&
	);

	AWL_DETAIL_SYMBOL
	~original_handle()
	override;

	AWL_DETAIL_SYMBOL
	HANDLE
	get() const
	override;
private:
	awl::backends::windows::system::event::handle_holder_unique_ptr const handle_;

	awl::event::connection_unique_ptr const connection_;
};

}
}
}
}
}

#endif
