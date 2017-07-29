#ifndef AWL_BACKENDS_X11_VISUAL_COPY_FROM_PARENT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_COPY_FROM_PARENT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/Xutil.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

class AWL_CLASS_SYMBOL copy_from_parent
:
	public awl::backends::x11::visual::object
{
	FCPPT_NONCOPYABLE(
		copy_from_parent
	);
public:
	AWL_DETAIL_SYMBOL
	copy_from_parent();

	AWL_DETAIL_SYMBOL
	~copy_from_parent()
	override;

	AWL_DETAIL_SYMBOL
	Visual *
	get() const
	override;

	AWL_DETAIL_SYMBOL
	XVisualInfo *
	info() const
	override;

	AWL_DETAIL_SYMBOL
	int
	depth() const
	override;
};

}
}
}
}

#endif
