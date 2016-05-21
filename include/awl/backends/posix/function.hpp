#ifndef AWL_BACKENDS_POSIX_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_FUNCTION_HPP_INCLUDED

#include <awl/backends/posix/event_fwd.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

typedef
void
function(
	awl::backends::posix::event const &
);

}
}
}

#endif
