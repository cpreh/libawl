#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/generic.hpp>
#include <awl/backends/windows/window/event/make.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/show.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/size.hpp>

awl::event::base_unique_ptr awl::backends::windows::window::event::make(
    awl::backends::windows::window::event::object const &_event)
{
  awl::window::reference const window_base{
      fcppt::reference_to_base<awl::window::object>(_event.window())};

  switch (_event.type().get())
  {
  case WM_CLOSE:
    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::close>(window_base));
  case WM_DESTROY:
    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::destroy>(window_base));
  case WM_SIZE:
    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::resize>(
            window_base,
            awl::window::dim(
                fcppt::cast::size<awl::window::dim::value_type>(LOWORD(_event.lparam().get())),
                fcppt::cast::size<awl::window::dim::value_type>(HIWORD(_event.lparam().get())))));
  case WM_SHOWWINDOW:
    switch (_event.wparam().get())
    {
    case TRUE:
      return fcppt::unique_ptr_to_base<awl::event::base>(
          fcppt::make_unique_ptr<awl::window::event::show>(window_base));
    case FALSE:
      return fcppt::unique_ptr_to_base<awl::event::base>(
          fcppt::make_unique_ptr<awl::window::event::hide>(window_base));
    }
    break;
  }

  return fcppt::unique_ptr_to_base<awl::event::base>(
      fcppt::make_unique_ptr<awl::backends::windows::window::event::generic>(
          _event.window(), _event.type(), _event.wparam(), _event.lparam()));
}
