#ifndef AWL_BACKENDS_WAYLAND_CURSOR_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_PREDEFINED_HPP_INCLUDED

#include <awl/backends/wayland/cursor/name_fwd.hpp>
#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/optional_fwd.hpp>
#include <awl/backends/wayland/cursor/theme_fwd.hpp>
#include <fcppt/nonmovable.hpp>
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

class predefined
:
	public awl::backends::wayland::cursor::object
{
	FCPPT_NONMOVABLE(
		predefined
	);
public:
	predefined(
		awl::backends::wayland::cursor::theme const &,
		awl::backends::wayland::cursor::name const &
	);

	~predefined()
	override;

	[[nodiscard]]
	awl::backends::wayland::cursor::optional
	get() const
	override;
private:
	wl_cursor *const impl_;
};

}
}
}
}

#endif
