#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

class AWL_DETAIL_CLASS_SYMBOL display
{
	FCPPT_NONCOPYABLE(
		display
	);
protected:
	AWL_DETAIL_SYMBOL
	display();
public:
	virtual
	wl_display *
	get() const = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~display() = 0;
};

}
}
}

#endif
