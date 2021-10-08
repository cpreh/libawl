#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/object_ref.hpp>
#include <awl/backends/x11/window/event/generic.hpp>
#include <awl/backends/x11/window/event/make.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/show.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/to_unsigned.hpp>

awl::event::base_unique_ptr awl::backends::x11::window::event::make(
    awl::backends::x11::window::object_ref const _window,
    awl::backends::x11::window::event::object const &_event)
{
  awl::window::reference const window_base{fcppt::reference_to_base<awl::window::object>(_window)};

  switch (_event.get().type)
  {
  case ConfigureNotify:
  {
    XConfigureEvent const request(_event.get().xconfigure);

    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::resize>(
            window_base,
            awl::window::dim{
                fcppt::cast::to_unsigned(request.width),
                fcppt::cast::to_unsigned(request.height)}));
  }
  case MapNotify:
    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::show>(window_base));
  case UnmapNotify:
    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::hide>(window_base));
  case DestroyNotify:
    return fcppt::unique_ptr_to_base<awl::event::base>(
        fcppt::make_unique_ptr<awl::window::event::destroy>(window_base));
  }

  return fcppt::unique_ptr_to_base<awl::event::base>(
      fcppt::make_unique_ptr<awl::backends::x11::window::event::generic>(_window, _event));
}
