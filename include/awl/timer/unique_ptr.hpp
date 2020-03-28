#ifndef AWL_TIMER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_TIMER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/timer/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace timer
{

using
unique_ptr
=
fcppt::unique_ptr<
	awl::timer::object
>;

}
}

#endif
