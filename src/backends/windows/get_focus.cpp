#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/windows.hpp>

HWND awl::backends::windows::get_focus() { return ::GetFocus(); }
