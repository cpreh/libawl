#ifndef AWL_BACKENDS_WAYLAND_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/shell_fwd.hpp>
#include <awl/backends/wayland/surface.hpp>
#include <awl/backends/wayland/window/object.hpp>
#include <awl/backends/wayland/window/shell_surface.hpp>
#include <awl/backends/wayland/window/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/signal/auto_connection.hpp>
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

class AWL_CLASS_SYMBOL original_object
:
	public awl::backends::wayland::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object(
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
	awl::window::event::processor &
	processor()
	override;

	AWL_DETAIL_SYMBOL
	wl_shell_surface *
	get() const
	override;
private:
	awl::visual::object const &visual_;

	awl::backends::wayland::surface surface_;

	awl::backends::wayland::window::shell_surface shell_surface_;

	fcppt::unique_ptr<
		awl::backends::wayland::window::event::processor
	> const processor_;

	awl::window::optional_dim size_;

	fcppt::signal::auto_connection const resize_connection_;
};

}
}
}
}

#endif
