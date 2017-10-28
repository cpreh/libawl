#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/add_time.hpp>
#include <awl/backends/windows/timer/due_time.hpp>
#include <awl/backends/windows/timer/file_time_to_large_integer.hpp>
#include <awl/backends/windows/timer/get_system_time.hpp>
#include <awl/backends/windows/timer/system_time_to_file_time.hpp>
#include <awl/timer/delay.hpp>


LARGE_INTEGER
awl::backends::windows::timer::due_time(
	awl::timer::delay const _delay
)
{
	return
		awl::backends::windows::timer::add_time(
			awl::backends::windows::timer::file_time_to_large_integer(
				awl::backends::windows::timer::system_time_to_file_time(
					awl::backends::windows::timer::get_system_time()
				)
			),
			_delay.get()
		);
}
