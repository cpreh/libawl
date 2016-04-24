#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/sync.hpp>
#include <awl/backends/x11/to_x11_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::sync(
	awl::backends::x11::display const &_display,
	awl::backends::x11::discard const _discard
)
{
	// always returns 1

	::XSync(
		_display.get(),
		awl::backends::x11::to_x11_bool(
			_discard.get()
		)
	);
}
