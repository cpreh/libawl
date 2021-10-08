#ifndef AWL_TIMER_CONST_REFERENCE_HPP_INCLUDED
#define AWL_TIMER_CONST_REFERENCE_HPP_INCLUDED

#include <awl/timer/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>

namespace awl::timer
{

using const_reference = fcppt::reference<awl::timer::object const>;

}

#endif
