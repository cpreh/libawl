#ifndef AWL_BACKENDS_X11_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/Xutil.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

class AWL_CLASS_SYMBOL object
:
	public awl::visual::object
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
	Visual *
	get() const = 0;

	virtual
	XVisualInfo *
	info() const = 0;

	virtual
	int
	depth() const = 0;
};

}
}
}
}

#endif
