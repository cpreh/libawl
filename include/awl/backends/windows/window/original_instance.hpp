#ifndef AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED

#include <awl/backends/windows/window/instance.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/math/box/basic_decl.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class AWL_CLASS_SYMBOL original_instance
:
	public awl::backends::windows::window::instance
{
	FCPPT_NONCOPYABLE(
		original_instance
	)
public:
	AWL_SYMBOL original_instance(
		awl::window::parameters const &,
		windows::wndclass &,
		windows::wndclass_remove_callback const &
	);

	AWL_SYMBOL ~original_instance();

	AWL_SYMBOL void
	show();

	AWL_SYMBOL awl::window::dim const
	size() const;

	AWL_SYMBOL HWND
	hwnd() const;
private:
	typedef fcppt::math::box::rect<
		LONG
	>::type decoration_rect;

	decoration_rect decoration_size_;

	HWND handle_;

	windows::wndclass_remove_callback const remove_wndclass_;
};

}
}
}
}

#endif