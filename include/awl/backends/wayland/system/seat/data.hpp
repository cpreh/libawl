#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_DATA_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/data_fwd.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <awl/event/container_reference.hpp>
#include <fcppt/noncopyable.hpp>
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
	FCPPT_NONCOPYABLE(
		data
	);
public:
	data(
		awl::backends::wayland::display_reference,
		awl::event::container_reference
	);

	~data();

	awl::backends::wayland::display_reference const display_;

	awl::backends::wayland::system::seat::caps_field caps_;

	awl::event::container_reference const events_;

	typedef
	fcppt::optional::object<
		awl::backends::wayland::system::seat::shared_ptr
	>
	optional_shared_ptr;

	optional_shared_ptr pointer_;
};

}
}
}
}
}

#endif
