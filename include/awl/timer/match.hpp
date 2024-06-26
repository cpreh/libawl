#ifndef AWL_TIMER_MATCH_HPP_INCLUDED
#define AWL_TIMER_MATCH_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/event/base_fwd.hpp>
#include <awl/timer/object_fwd.hpp>

namespace awl::timer
{

AWL_DETAIL_SYMBOL
bool match(awl::event::base const &, awl::timer::object const &);

}

#endif
