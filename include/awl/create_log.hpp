#ifndef AWL_CREATE_LOG_HPP_INCLUDED
#define AWL_CREATE_LOG_HPP_INCLUDED

#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/parameters.hpp>


namespace awl
{

fcppt::log::parameters
create_log(
	fcppt::log::location const &
);

}

#endif
