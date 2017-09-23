#ifndef AWL_TIMER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_TIMER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/timer/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace timer
{

typedef
fcppt::unique_ptr<
	awl::timer::object
>
unique_ptr;

}
}

#endif
