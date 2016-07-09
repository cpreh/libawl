#include <awl/impl/create_log.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/format/optional_function.hpp>


fcppt::log::parameters
awl::impl::create_log(
	fcppt::log::context &_context,
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters{
			_context,
			_location,
			fcppt::log::default_level_streams(
				fcppt::io::clog()
			),
			fcppt::log::format::optional_function()
		};
}
