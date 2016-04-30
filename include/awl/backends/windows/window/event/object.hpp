#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

class object
{
public:
	AWL_DETAIL_SYMBOL
	object(
		awl::backends::windows::wparam,
		awl::backends::windows::lparam
	);

	AWL_DETAIL_SYMBOL
	awl::backends::windows::wparam
	wparam() const;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::lparam
	lparam() const;
private:
	awl::backends::windows::wparam wparam_;

	awl::backends::windows::lparam lparam_;
};

}
}
}
}
}

#endif
