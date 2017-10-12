#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_comparison.hpp>


bool
awl::backends::wayland::operator==(
	awl::backends::wayland::display const &_left,
	awl::backends::wayland::display const &_right
)
{
	return
		_left.get()
		==
		_right.get();
}
