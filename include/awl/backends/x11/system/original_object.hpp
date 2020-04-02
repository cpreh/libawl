#ifndef AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/log/context_reference_fwd.hpp>


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
	FCPPT_NONMOVABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_object(
		fcppt::log::context_reference
	);

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::window::object_unique_ptr
	create_window(
		awl::window::parameters const &
	)
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::system::event::processor &
	processor()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::visual::object_unique_ptr
	default_visual()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::cursor::object_unique_ptr
	create_cursor(
		awl::cursor::optional_type const &
	)
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::x11::display &
	display()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::x11::screen
	screen() const
	override;
private:
	awl::backends::x11::original_display display_;

	awl::backends::x11::screen const screen_;

	fcppt::unique_ptr<
		awl::backends::x11::system::event::original_processor
	> const processor_;
};

}
}
}
}

#endif
