#include <awl/exception.hpp>
#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/sync.hpp>
#include <awl/backends/x11/window/common_object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/rect.hpp>
#include <awl/window/dim.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::common_object::common_object()
:
	awl::backends::x11::window::object()
{
}

awl::backends::x11::window::common_object::~common_object()
{
}

void
awl::backends::x11::window::common_object::show()
{
	// always returns 1
	::XMapWindow(
		this->display().get(),
		this->get()
	);

	awl::backends::x11::sync(
		this->display(),
		awl::backends::x11::discard(
			false
		)
	);
}

awl::window::dim
awl::backends::x11::window::common_object::size() const
{
	return
		fcppt::math::dim::to_unsigned(
			this->rect().size()
		);
}

awl::backends::x11::window::rect
awl::backends::x11::window::common_object::rect() const
{
	Window root_return;

	int
		x_return,
		y_return;

	unsigned
		width_return,
		height_return,
		border_width_return,
		depth_return;

	if(
		::XGetGeometry(
			display().get(),
			get(),
			&root_return,
			&x_return,
			&y_return,
			&width_return,
			&height_return,
			&border_width_return,
			&depth_return
		)
		== 0
	)
		throw
			awl::exception{
				FCPPT_TEXT("XGetGeometry() failed!")
			};

	return
		awl::backends::x11::window::rect{
			awl::backends::x11::window::rect::vector{
				x_return,
				y_return
			},
			awl::backends::x11::window::rect::dim{
				fcppt::cast::to_signed(
					width_return
				),
				fcppt::cast::to_signed(
					height_return
				)
			}
		};
}
