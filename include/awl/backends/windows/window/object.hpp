#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref_fwd.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;

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
