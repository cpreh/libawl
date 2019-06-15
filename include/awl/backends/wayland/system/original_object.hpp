#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/original_display.hpp>
#include <awl/backends/wayland/cursor/theme.hpp>
#include <awl/backends/wayland/system/object.hpp>
#include <awl/backends/wayland/system/event/processor_unique_ptr.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/object.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{

class original_object
:
	public awl::backends::wayland::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_object(
		fcppt::log::context &
	);

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
	awl::system::event::processor &
	processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::visual::object_unique_ptr
	default_visual()
	override;

	AWL_DETAIL_SYMBOL
	awl::cursor::object_unique_ptr
	create_cursor(
		awl::cursor::optional_type const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::display &
	display()
	override;
private:
	fcppt::log::object log_;

	awl::backends::wayland::original_display display_;

	awl::backends::wayland::system::event::processor_unique_ptr const processor_;

	awl::backends::wayland::cursor::theme const cursor_theme_;
};

}
}
}
}

#endif
