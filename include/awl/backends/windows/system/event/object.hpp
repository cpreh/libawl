#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/system/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>


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

class object
{
public:
	AWL_DETAIL_SYMBOL
	object(
		awl::backends::windows::event::wparam,
		awl::backends::windows::event::lparam
	);

	AWL_DETAIL_SYMBOL
	awl::backends::windows::event::wparam
	wparam() const;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::event::lparam
	lparam() const;
private:
	awl::backends::windows::event::wparam wparam_;

	awl::backends::windows::event::lparam lparam_;
};

}
}
}
}
}

#endif
