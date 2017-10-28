#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/file_time_to_large_integer.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/size.hpp>


LARGE_INTEGER
awl::backends::windows::timer::file_time_to_large_integer(
	FILETIME const &_time
)
{
	LARGE_INTEGER result;

	result.LowPart =
		_time.dwLowDateTime;

	result.HighPart =
		fcppt::cast::size<
			LONG
		>(
			fcppt::cast::to_signed(
				_time.dwHighDateTime
			)
		);

	return
		result;
}
