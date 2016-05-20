#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/seat.hpp>
#include <awl/backends/wayland/system/seat/caps_callback.hpp>
#include <awl/backends/wayland/system/seat/caps_field_fwd.hpp>
#include <awl/backends/wayland/system/seat/data.hpp>
#include <awl/backends/wayland/system/seat/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


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

class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	explicit
	object(
		awl::backends::wayland::seat &&
	);

	object(
		object &&
	);

	object &
	operator=(
		object &&
	);

	~object();

	awl::backends::wayland::registry_id
	name() const;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	caps_callback(
		awl::backends::wayland::system::seat::caps_callback const &
	);

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::system::seat::caps_field
	caps() const;
private:
	awl::backends::wayland::seat impl_;

	awl::backends::wayland::system::seat::data data_;
};

}
}
}
}
}

#endif
