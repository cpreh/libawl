#include <awl/impl/create_log.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/format/optional_function.hpp>


fcppt::log::parameters
awl::impl::create_log(
	fcppt::log::name const &_name
)
{
	return
		fcppt::log::parameters{
			_name,
			fcppt::log::default_level_streams(
				fcppt::io::clog()
			),
			fcppt::log::format::optional_function()
		};
}
