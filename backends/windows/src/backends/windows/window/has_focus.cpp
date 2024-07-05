#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/window/has_focus.hpp>
#include <awl/backends/windows/window/object.hpp>

bool awl::backends::windows::window::has_focus(
    awl::backends::windows::window::object const &_window)
{
  return awl::backends::windows::get_focus() == _window.hwnd();
}
