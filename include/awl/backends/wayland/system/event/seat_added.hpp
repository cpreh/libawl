#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_ADDED_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_ADDED_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/seat_added_fwd.hpp>
#include <awl/backends/wayland/system/event/seat_base.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::wayland::system::event
{

class AWL_DETAIL_CLASS_SYMBOL seat_added
:
	public awl::backends::wayland::system::event::seat_base
{
	FCPPT_NONMOVABLE(
		seat_added
	);
public:
	AWL_DETAIL_SYMBOL
	seat_added(
		awl::backends::wayland::display_reference,
		awl::backends::wayland::system::seat::shared_ptr
	);

	AWL_DETAIL_SYMBOL
	~seat_added()
	override;
};

}

#endif
