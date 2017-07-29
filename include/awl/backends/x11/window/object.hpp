#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref_fwd.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

// TODO: Derive from window::object again!
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
	bool
	destroyed() const = 0;

	virtual
	awl::backends::x11::display &
	display() const = 0;

	virtual
	awl::backends::x11::screen
	screen() const = 0;

	virtual
	awl::backends::x11::visual::object const &
	x11_visual() const = 0;

	virtual
	awl::backends::x11::window::rect
	rect() const = 0;

	virtual
	Window
	get() const = 0;

	virtual
	awl::backends::x11::window::const_optional_class_hint_ref
	class_hint() const = 0;
};

}
}
}
}

#endif
