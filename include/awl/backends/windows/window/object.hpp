#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref_fwd.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

// TODO: Derive from awl::window::object again
class AWL_CLASS_SYMBOL object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~object() = 0;

	virtual
	HWND
	hwnd() const = 0;

	virtual
	awl::backends::windows::cursor::const_optional_object_ref
	cursor() const = 0;
};

}
}
}
}

#endif
