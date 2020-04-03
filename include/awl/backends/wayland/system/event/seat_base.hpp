#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_BASE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_BASE_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/base.hpp>
#include <awl/backends/wayland/system/event/seat_base_fwd.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL seat_base
:
	public awl::backends::wayland::system::event::base
{
	FCPPT_NONMOVABLE(
		seat_base
	);
public:
	AWL_DETAIL_SYMBOL
	seat_base(
		awl::backends::wayland::display_reference,
		awl::backends::wayland::system::seat::shared_ptr
	);

	AWL_DETAIL_SYMBOL
	~seat_base()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::wayland::system::seat::shared_ptr const &
	get() const;
private:
	awl::backends::wayland::system::seat::shared_ptr const seat_;
};

}
}
}
}
}

#endif
