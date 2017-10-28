#ifndef AWL_BACKENDS_WINDOWS_TIMER_FILE_TIME_TO_LARGE_INTEGER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_FILE_TIME_TO_LARGE_INTEGER_HPP_INCLUDED

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
LARGE_INTEGER
file_time_to_large_integer(
	FILETIME const &
);

}
}
}
}

#endif
