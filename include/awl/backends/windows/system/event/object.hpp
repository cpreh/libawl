#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/wparam.hpp>
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
		awl::backends::windows::message_type,
		awl::backends::windows::wparam,
		awl::backends::windows::lparam
	);

	AWL_DETAIL_SYMBOL
	awl::backends::windows::message_type
	type() const;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::wparam
	wparam() const;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::lparam
	lparam() const;
private:
	awl::backends::windows::message_type const type_;

	awl::backends::windows::wparam const wparam_;

	awl::backends::windows::lparam const lparam_;
};

}
}
}
}
}

#endif
