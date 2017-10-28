#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_HOLDER_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/handle_holder_fwd.hpp>
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

class handle_holder
{
	FCPPT_NONCOPYABLE(
		handle_holder
	);
public:
	AWL_DETAIL_SYMBOL
	handle_holder();

	AWL_DETAIL_SYMBOL
	~handle_holder();

	AWL_DETAIL_SYMBOL
	HANDLE
	get() const;
private:
	HANDLE handle_;
};

}
}
}
}
}

#endif
