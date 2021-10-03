#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_SHARED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_SEAT_SHARED_PTR_HPP_INCLUDED

#include <awl/backends/wayland/system/seat/object_fwd.hpp>
#include <fcppt/shared_ptr_impl.hpp>


namespace awl::backends::wayland::system::seat
{

using
shared_ptr
=
fcppt::shared_ptr<
	awl::backends::wayland::system::seat::object
>;

}

#endif
