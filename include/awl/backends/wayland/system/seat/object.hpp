#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/seat.hpp>
#include <awl/backends/wayland/system/seat/data.hpp>
#include <awl/backends/wayland/system/seat/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/container_reference.hpp>
#include <fcppt/enable_shared_from_this_decl.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::wayland::system::seat
{

class object
:
	public
		fcppt::enable_shared_from_this<
			awl::backends::wayland::system::seat::object
		>
{
	FCPPT_NONMOVABLE(
		object
	);
public:
	object(
		awl::backends::wayland::seat &&,
		awl::backends::wayland::display_reference,
		awl::event::container_reference
	);

	~object();

	void
	init_ptr();

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::wayland::registry_id
	name() const;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::wayland::seat &
	get();

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::wayland::seat const &
	get() const;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::wayland::system::seat::caps_field
	caps() const;
private:
	awl::backends::wayland::seat impl_;

	awl::backends::wayland::system::seat::data data_;
};

}

#endif
