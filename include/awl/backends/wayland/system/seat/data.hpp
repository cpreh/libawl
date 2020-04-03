#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_DATA_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/data_fwd.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <awl/event/container_reference.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace seat
{

struct data
{
	FCPPT_NONMOVABLE(
		data
	);
public:
	data(
		awl::backends::wayland::display_reference,
		awl::event::container_reference
	);

	~data();

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::display_reference const display_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::system::seat::caps_field caps_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::event::container_reference const events_;

	using
	optional_shared_ptr
	=
	fcppt::optional::object<
		awl::backends::wayland::system::seat::shared_ptr
	>;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	optional_shared_ptr pointer_;
};

}
}
}
}
}

#endif
