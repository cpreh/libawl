#include <awl/impl/backends/x11/log_name.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/name.hpp>


fcppt::log::name
awl::impl::backends::x11::log_name()
{
	return
		fcppt::log::name{
			FCPPT_TEXT("x11")
		};
}
