#ifndef AWL_BACKENDS_POSIX_MATCH_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_MATCH_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base_fwd.hpp>

namespace awl::backends::posix
{

AWL_DETAIL_SYMBOL
bool match(awl::event::base const &, awl::backends::posix::fd);

}

#endif
