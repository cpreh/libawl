#ifndef AWL_BACKENDS_POSIX_OPTIONAL_DURATION_FWD_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_OPTIONAL_DURATION_FWD_HPP_INCLUDED

#include <awl/backends/posix/duration.hpp>
#include <fcppt/optional/object_fwd.hpp>

namespace awl::backends::posix
{

using optional_duration = fcppt::optional::object<awl::backends::posix::duration>;

}

#endif
