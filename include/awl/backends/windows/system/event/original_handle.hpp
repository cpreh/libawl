#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_HANDLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_HANDLE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_destroy_callback.hpp>
#include <awl/detail/symbol.hpp>
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

class original_handle
:
	public awl::backends::windows::system::event::handle
{
	FCPPT_NONCOPYABLE(
		original_handle
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_handle(
		awl::backends::windows::system::event::handle_destroy_callback const &
	);

	AWL_DETAIL_SYMBOL
	~original_handle()
	override;

	AWL_DETAIL_SYMBOL
	HANDLE
	get() const
	override;

	AWL_DETAIL_SYMBOL
	bool
	ready() const
	override;
private:
	awl::backends::windows::system::event::handle_destroy_callback const on_destroy_;

	HANDLE handle_;
};

}
}
}
}
}

#endif
