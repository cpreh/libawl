#ifndef AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/optional_object_unique_ptr_fwd.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{

class original_object
:
	public awl::backends::x11::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object();

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::object_unique_ptr
	create_window(
		awl::window::parameters const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::processor_unique_ptr
	create_processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::visual::object_unique_ptr
	default_visual()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::optional_object_unique_ptr
	focus_window()
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::display &
	display()
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::screen
	screen() const
	override;
private:
	awl::backends::x11::original_display display_;

	awl::backends::x11::screen const screen_;
};

}
}
}
}

#endif
