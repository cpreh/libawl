#include <awl/backends/windows/system/event/base.hpp>
#include <awl/backends/windows/system/event/generic.hpp>
#include <awl/backends/windows/system/event/object.hpp>

awl::backends::windows::system::event::generic::generic(
    awl::backends::windows::system::event::object const &_event)
    : awl::backends::windows::system::event::base{}, event_{_event}
{
}

awl::backends::windows::system::event::generic::~generic() {}

awl::backends::windows::system::event::object const &
awl::backends::windows::system::event::generic::get() const
{
  return event_;
}
