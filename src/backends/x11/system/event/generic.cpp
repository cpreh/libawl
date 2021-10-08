#include <awl/exception.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/system/event/generic.hpp>
#include <awl/event/base.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::system::event::generic::generic(
    awl::backends::x11::display_ref const _display, XGenericEventCookie const &_event)
    : awl::event::base(), display_{_display}, event_{_event}
{
  if (::XGetEventData(this->display().get(), &event_) == False)
  {
    throw awl::exception{FCPPT_TEXT("XGetEventData failed!")};
  }
}

awl::backends::x11::system::event::generic::~generic()
{
  ::XFreeEventData(this->display().get(), &event_);
}

XGenericEventCookie const &awl::backends::x11::system::event::generic::get() const
{
  return event_;
}

void const *awl::backends::x11::system::event::generic::data() const { return event_.data; }

awl::backends::x11::display &awl::backends::x11::system::event::generic::display() const
{
  return display_.get();
}
