#include <awl/backends/windows/has_last_error.hpp>
#include <awl/backends/windows/windows.hpp>

bool awl::backends::windows::has_last_error() { return ::GetLastError() != ERROR_SUCCESS; }
