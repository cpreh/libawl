#include <awl/backends/windows/window/reference.hpp>
#include <awl/backends/windows/window/user_data.hpp>
#include <awl/event/container_reference.hpp>

awl::backends::windows::window::user_data::user_data(
    awl::backends::windows::window::reference const _window,
    awl::event::container_reference const _events)
    : window_{_window}, events_{_events}
{
}

awl::backends::windows::window::user_data::~user_data() {}

awl::backends::windows::window::reference awl::backends::windows::window::user_data::window() const
{
  return window_;
}

awl::event::container_reference awl::backends::windows::window::user_data::events() const
{
  return events_;
}
