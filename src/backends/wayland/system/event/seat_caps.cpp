#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/seat_base.hpp>
#include <awl/backends/wayland/system/event/seat_caps.hpp>
#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::system::event::seat_caps::seat_caps(
	awl::backends::wayland::display_reference const _display,
	awl::backends::wayland::system::seat::shared_ptr _seat,
	awl::backends::wayland::system::seat::caps_field const _caps
)
:
	awl::backends::wayland::system::event::seat_base{
		_display,
		std::move(
			_seat
		)
	},
	caps_{
		_caps
	}
{
}

awl::backends::wayland::system::event::seat_caps::~seat_caps()
{
}

awl::backends::wayland::system::seat::caps_field
awl::backends::wayland::system::event::seat_caps::caps() const
{
	return
		caps_;
}
