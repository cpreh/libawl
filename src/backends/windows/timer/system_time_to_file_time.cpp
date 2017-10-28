#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/system_time_to_file_time.hpp>
#include <fcppt/text.hpp>


FILETIME
awl::backends::windows::timer::system_time_to_file_time(
	SYSTEMTIME const &_time
)
{
	FILETIME result;

	if(
		::SystemTimeToFileTime(
			&_time,
			&result
		)
		==
		0
	)
		throw
			awl::exception{
				FCPPT_TEXT("SystemTimeToFileTime failed")
			};

	return
		result;
}
