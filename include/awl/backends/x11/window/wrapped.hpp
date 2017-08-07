#ifndef AWL_BACKENDS_X11_WINDOW_WRAPPED_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_WRAPPED_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref_fwd.hpp>
#include <awl/backends/x11/window/optional_class_hint.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_DETAIL_CLASS_SYMBOL wrapped
:
	public awl::backends::x11::window::base
{
	FCPPT_NONCOPYABLE(
		wrapped
	);
public:
	AWL_DETAIL_SYMBOL
	wrapped(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		Window
	);

	AWL_DETAIL_SYMBOL
	~wrapped()
	override;

	AWL_DETAIL_SYMBOL
	bool
	destroyed() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::display &
	display() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::screen
	screen() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::visual::object const &
	x11_visual() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::rect
	rect() const
	override;

	AWL_DETAIL_SYMBOL
	Window
	get() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::const_optional_class_hint_ref
	class_hint() const
	override;
private:
	awl::backends::x11::display &display_;

	awl::backends::x11::screen const screen_;

	Window const window_;

	awl::backends::x11::visual::object_unique_ptr const visual_;

	awl::backends::x11::window::optional_class_hint const class_hint_;
};

}
}
}
}

#endif
