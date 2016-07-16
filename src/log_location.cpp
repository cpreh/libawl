#include <awl/log_location.hpp>
#include <awl/impl/log_name.hpp>
#include <fcppt/log/location.hpp>


fcppt::log::location
awl::log_location()
{
	return
		fcppt::log::location{
			awl::impl::log_name()
		};
}
