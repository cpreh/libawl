#ifndef AWL_BACKENDS_WAYLAND_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/surface.hpp>
#include <awl/backends/wayland/window/object.hpp>
#include <awl/backends/wayland/window/shell_surface.hpp>
#include <awl/backends/wayland/window/event/data.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace window
{

class AWL_DETAIL_CLASS_SYMBOL original_object
:
	public awl::backends::wayland::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object(
		fcppt::log::object &,
		awl::event::container_reference,
		awl::backends::wayland::display const &,
		awl::backends::wayland::compositor const &,
		awl::backends::wayland::shell const &,
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
	wl_surface *
	surface() const
	override;

	AWL_DETAIL_SYMBOL
	wl_shell_surface *
	get() const
	override;
private:
	awl::backends::wayland::display const &display_;

	awl::visual::object const &visual_;

	awl::backends::wayland::surface surface_;

	awl::backends::wayland::window::shell_surface shell_surface_;

	awl::backends::wayland::window::event::data data_;
};

}
}
}
}

#endif
