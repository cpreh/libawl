#ifndef AWL_BACKENDS_WAYLAND_CURSOR_THEME_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_THEME_HPP_INCLUDED

#include <awl/backends/wayland/shm_fwd.hpp>
#include <awl/backends/wayland/cursor/theme_fwd.hpp>
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

class theme
{
	FCPPT_NONCOPYABLE(
		theme
	);
public:
	explicit
	theme(
		awl::backends::wayland::shm const &
	);

	~theme();

	wl_cursor_theme *
	get() const;
private:
	wl_cursor_theme *const impl_;
};

}
}
}
}

#endif
