#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/data.hpp>
#include <fcppt/signal/object_impl.hpp>


awl::backends::wayland::system::seat::data::data()
:
	caps_{
		awl::backends::wayland::system::seat::caps_field::null()
	},
	caps_signal_{}
{
}

awl::backends::wayland::system::seat::data::data(
	data &&
)
= default;

awl::backends::wayland::system::seat::data &
awl::backends::wayland::system::seat::data::operator=(
	data &&
)
= default;

awl::backends::wayland::system::seat::data::~data()
{
}
