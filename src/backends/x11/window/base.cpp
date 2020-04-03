#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/sync.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/rect.hpp>
#include <awl/visual/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::base::base()
:
	awl::window::object()
{
}

awl::backends::x11::window::base::~base()
= default;

void
awl::backends::x11::window::base::show()
{
	// always returns 1
	::XMapRaised(
		this->display().get().get(),
		this->get()
	);

	awl::backends::x11::sync(
		this->display().get(),
		awl::backends::x11::discard{
			false
		}
	);
}

awl::window::dim
awl::backends::x11::window::base::size() const
{
	return
		fcppt::math::dim::to_unsigned(
			this->rect().size()
		);
}

awl::visual::object const &
awl::backends::x11::window::base::visual() const
{
	return
		this->x11_visual();
}
