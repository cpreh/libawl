#ifndef AWL_BACKENDS_WINDOWS_TIMER_SYSTEM_TIME_TO_FILE_TIME_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_SYSTEM_TIME_TO_FILE_TIME_HPP_INCLUDED

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
FILETIME
system_time_to_file_time(
	SYSTEMTIME const &
);

}
}
}
}

#endif
