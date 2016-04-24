#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/flush.hpp>


void
awl::backends::x11::flush(
	awl::backends::x11::display const &_display
)
{
	::XFlush(
		_display.get()
	);
}
