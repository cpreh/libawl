#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/seat_added.hpp>
#include <awl/backends/wayland/system/event/seat_base.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::system::event::seat_added::seat_added(
	awl::backends::wayland::display_reference const _display,
	awl::backends::wayland::system::seat::shared_ptr _seat
)
:
	awl::backends::wayland::system::event::seat_base{
		_display,
		std::move(
			_seat
		)
	}
{
}

awl::backends::wayland::system::event::seat_added::~seat_added()
= default;
