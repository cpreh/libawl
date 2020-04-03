#include <awl/backends/wayland/cursor/invisible.hpp>
#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/optional.hpp>


awl::backends::wayland::cursor::invisible::invisible()
:
	awl::backends::wayland::cursor::object()
{
}

awl::backends::wayland::cursor::invisible::~invisible()
= default;

awl::backends::wayland::cursor::optional
awl::backends::wayland::cursor::invisible::get() const
{
	return
		awl::backends::wayland::cursor::optional{};
}
