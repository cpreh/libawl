#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/get_system_time.hpp>


SYSTEMTIME
awl::backends::windows::timer::get_system_time()
{
	SYSTEMTIME result;

	::GetSystemTime(
		&result
	);

	return
		result;
}
