#ifndef AWL_BACKENDS_WAYLAND_CURSOR_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_INVISIBLE_HPP_INCLUDED

#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/optional_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

class invisible
:
	public awl::backends::wayland::cursor::object
{
	FCPPT_NONCOPYABLE(
		invisible
	);
public:
	invisible();

	~invisible()
	override;

	awl::backends::wayland::cursor::optional
	get() const
	override;
};

}
}
}
}

#endif
