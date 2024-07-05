#ifndef AWL_BACKENDS_X11_LOG_LOCATION_HPP_INCLUDED
#define AWL_BACKENDS_X11_LOG_LOCATION_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/log/location.hpp>

namespace awl::backends::x11
{

AWL_DETAIL_SYMBOL
fcppt::log::location log_location();

}

#endif
