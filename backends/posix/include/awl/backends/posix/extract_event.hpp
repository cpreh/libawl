#ifndef AWL_BACKENDS_POSIX_EXTRACT_EVENT_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_EXTRACT_EVENT_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/event/container.hpp>
#include <fcppt/function_fwd.hpp>

namespace awl::backends::posix
{

awl::event::container extract_event(
    awl::event::container &&, awl::backends::posix::fd, fcppt::function<awl::event::container()>);

}

#endif
