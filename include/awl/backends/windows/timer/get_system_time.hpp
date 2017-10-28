#ifndef AWL_BACKENDS_WINDOWS_TIMER_GET_SYSTEM_TIME_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_GET_SYSTEM_TIME_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace timer
{

AWL_DETAIL_SYMBOL
SYSTEMTIME
get_system_time();

}
}
}
}

#endif
