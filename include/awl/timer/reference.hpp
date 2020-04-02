#ifndef AWL_TIMER_REFERENCE_HPP_INCLUDED
#define AWL_TIMER_REFERENCE_HPP_INCLUDED

#include <awl/timer/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace timer
{

using
reference
=
fcppt::reference<
	awl::timer::object
>;

}
}

#endif
