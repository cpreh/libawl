#ifndef AWL_BACKENDS_WINDOWS_TIMER_DUE_TIME_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_DUE_TIME_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/timer/delay.hpp>

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
due_time(awl::timer::delay);

}
}
}
}

#endif
