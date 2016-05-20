#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_DATA_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/caps_function.hpp>
#include <awl/backends/wayland/system/seat/data_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/object_decl.hpp>


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
	FCPPT_NONCOPYABLE(
		data
	);
public:
	data();

	data(
		data &&
	);

	data &
	operator=(
		data &&
	);

	~data();

	awl::backends::wayland::system::seat::caps_field caps_;

	fcppt::signal::object<
		awl::backends::wayland::system::seat::caps_function
	> caps_signal_;
};

}
}
}
}
}

#endif
