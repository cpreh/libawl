#ifndef AWL_BACKENDS_WINDOWS_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/object_fwd.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

class object
{
public:
	AWL_DETAIL_SYMBOL
	object(
		awl::backends::windows::event::type,
		awl::backends::windows::event::wparam,
		awl::backends::windows::event::lparam
	);

	AWL_DETAIL_SYMBOL
	awl::backends::windows::event::type const
	type() const;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::event::wparam const
	wparam() const;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::event::lparam const
	lparam() const;
private:
	awl::backends::windows::event::type type_;

	awl::backends::windows::event::wparam wparam_;

	awl::backends::windows::event::lparam lparam_;
};

}
}
}
}

#endif
