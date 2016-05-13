#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref_fwd.hpp>
#include <awl/backends/x11/window/hints.hpp>
#include <awl/backends/x11/window/holder.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/window/original_object_fwd.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/backends/x11/window/event/scoped_processor.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/object_decl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_CLASS_SYMBOL original_object
:
	public awl::backends::x11::window::object,
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		awl::backends::x11::system::event::original_processor &,
		awl::window::parameters const &
	);

	AWL_DETAIL_SYMBOL
	~original_object()
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
	awl::visual::object const &
	visual() const
	override;

	AWL_DETAIL_SYMBOL
	awl::window::event::processor &
	processor()
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

	AWL_DETAIL_SYMBOL
	void
	destroy();

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::event::processor &
	x11_processor();
private:
	awl::backends::x11::display &display_;

	awl::backends::x11::screen const screen_;

	awl::backends::x11::visual::object const &visual_;

	awl::backends::x11::colormap const colormap_;

	awl::backends::x11::window::hints const hints_;

	typedef
	fcppt::unique_ptr<
		awl::backends::x11::window::original_class_hint
	>
	original_class_hint_unique_ptr;

	typedef
	fcppt::optional::object<
		original_class_hint_unique_ptr
	>
	optional_original_class_hint_unique_ptr;

	optional_original_class_hint_unique_ptr const class_hint_;

	awl::backends::x11::window::holder window_;

	fcppt::unique_ptr<
		awl::backends::x11::window::event::processor
	> const processor_;

	awl::backends::x11::window::event::scoped_processor const scoped_processor_;
};

}
}
}
}

#endif
