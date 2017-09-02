#ifndef AWL_BACKENDS_WAYLAND_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/window/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/object.hpp>
#include <fcppt/noncopyable.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;

	virtual
	wl_surface *
	surface() const = 0;

	virtual
	wl_shell_surface *
	get() const = 0;
};

}
}
}
}

#endif
