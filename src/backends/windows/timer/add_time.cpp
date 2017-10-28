#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/add_time.hpp>
#include <awl/timer/duration.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <fcppt/config/external_end.hpp>


LARGE_INTEGER
awl::backends::windows::timer::add_time(
	LARGE_INTEGER _result,
	awl::timer::duration const _duration
)
{
	std::chrono::nanoseconds const nsecs{
		std::chrono::duration_cast<
			std::chrono::nanoseconds
		>(
			_duration
		)
		/
		100
	};

	_result.QuadPart +=
		nsecs.count();

	return
		_result;
}
