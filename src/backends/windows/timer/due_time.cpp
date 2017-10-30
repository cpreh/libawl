#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/due_time.hpp>
#include <awl/timer/delay.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <fcppt/config/external_end.hpp>


LARGE_INTEGER
awl::backends::windows::timer::due_time(
	awl::timer::delay const _delay
)
{
	std::chrono::nanoseconds const nsecs{
		std::chrono::duration_cast<
			std::chrono::nanoseconds
		>(
			_delay.get()
		)
		/
		100
	};

	LARGE_INTEGER result;

	result.QuadPart =
		-
		nsecs.count();

	return
		result;
}
