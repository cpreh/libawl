#include <awl/log_location.hpp>
#include <awl/backends/x11/log_location.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/location.hpp>


fcppt::log::location
awl::backends::x11::log_location()
{
	return
		awl::log_location()
		/
		FCPPT_TEXT("x11");
}
