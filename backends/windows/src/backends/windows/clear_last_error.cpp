#include <awl/backends/windows/clear_last_error.hpp>
#include <awl/backends/windows/windows.hpp>

void awl::backends::windows::clear_last_error() { ::SetLastError(ERROR_SUCCESS); }
