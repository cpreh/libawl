#ifndef AWL_BACKENDS_WINDOWS_TIMER_ADD_TIME_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_ADD_TIME_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/timer/duration.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace timer
{

AWL_DETAIL_SYMBOL
LARGE_INTEGER
add_time(
	LARGE_INTEGER,
	awl::timer::duration
);

}
}
}
}

#endif
