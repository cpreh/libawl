#ifndef AWL_BACKENDS_X11_VISUAL_WRAPPED_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_WRAPPED_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/Xutil.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/detail/class_symbol.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL wrapped
:
	public awl::backends::x11::visual::object
{
	FCPPT_NONCOPYABLE(
		wrapped
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	wrapped(
		awl::backends::x11::visual::info_unique_ptr &&
	);

	AWL_DETAIL_SYMBOL
	~wrapped()
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
private:
	awl::backends::x11::visual::info_unique_ptr const info_;
};

}
}
}
}

#endif
