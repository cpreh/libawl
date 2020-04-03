#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/base.hpp>
#include <awl/event/base.hpp>


awl::backends::wayland::system::event::base::base(
	awl::backends::wayland::display_reference const _display
)
:
	awl::event::base{},
	display_{
		_display
	}
{
}

awl::backends::wayland::system::event::base::~base()
= default;

awl::backends::wayland::display &
awl::backends::wayland::system::event::base::display() const
{
	return
		display_.get();
}
