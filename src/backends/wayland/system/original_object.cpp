#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/system/object.hpp>
#include <awl/backends/wayland/system/original_object.hpp>


awl::backends::wayland::system::original_object::original_object()
:
	awl::backends::wayland::system::object(),
	display_()
{
}

awl::backends::wayland::system::original_object::~original_object()
{
}

awl::backends::wayland::display &
awl::backends::wayland::system::original_object::display()
{
	return
		display_;
}
