#include <awl/log_location.hpp>
#include <awl/impl/create_log.hpp>
#include <awl/impl/log.hpp>
#include <fcppt/log/object.hpp>


namespace
{

fcppt::log::object logger(
	awl::impl::create_log(
		awl::log_location()
	)
);

}

fcppt::log::object &
awl::impl::log()
{
	return
		logger;
}
