#include <awl/impl/backends/wayland/log_name.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/name.hpp>


fcppt::log::name
awl::impl::backends::wayland::log_name()
{
	return
		fcppt::log::name{
			FCPPT_TEXT("wayland")
		};
}
