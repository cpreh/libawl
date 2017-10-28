#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/handle_fwd.hpp>
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

class handle
{
	FCPPT_NONCOPYABLE(
		handle
	);
protected:
	AWL_DETAIL_SYMBOL
	handle();
public:
	virtual
	HANDLE
	get() const = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~handle() = 0;
};

}
}
}
}
}

#endif
