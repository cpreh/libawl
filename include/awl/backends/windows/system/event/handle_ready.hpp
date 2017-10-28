#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_READY_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_READY_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/base.hpp>
#include <awl/backends/windows/system/event/handle_ready_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL handle_ready
:
	public awl::backends::windows::system::event::base
{
	FCPPT_NONCOPYABLE(
		handle_ready
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	handle_ready(
		HANDLE
	);

	AWL_DETAIL_SYMBOL
	~handle_ready()
	override;

	AWL_DETAIL_SYMBOL
	HANDLE
	get() const;
private:
	HANDLE const handle_;
};

}
}
}
}
}

#endif
