#ifndef AWL_BACKENDS_WINDOWS_WINDOW_COMMON_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_COMMON_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/rect_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class AWL_CLASS_SYMBOL common_object
:
	public awl::backends::windows::window::object
{
	FCPPT_NONCOPYABLE(
		common_object
	);
public:
	AWL_DETAIL_SYMBOL
	common_object();

	AWL_DETAIL_SYMBOL
	~common_object()
	override;

	AWL_DETAIL_SYMBOL
	void
	show()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::dim
	size() const
	override;

	AWL_DETAIL_SYMBOL
	awl::window::rect
	rect() const
	override;

	AWL_DETAIL_SYMBOL
	bool
	equal_to(
		awl::window::object const &
	) const
	override;
};

}
}
}
}

#endif
