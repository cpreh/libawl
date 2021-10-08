#ifndef AWL_BACKENDS_POSIX_DURATION_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_DURATION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::posix
{

using duration = std::chrono::milliseconds;

}

#endif
