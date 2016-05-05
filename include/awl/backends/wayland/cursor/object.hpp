#ifndef AWL_BACKENDS_WAYLAND_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-cursor.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

class AWL_CLASS_SYMBOL object
:
	public awl::cursor::object
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
	wl_cursor *
	get() const = 0;
};

}
}
}
}

#endif
