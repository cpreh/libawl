#include <awl/backends/x11/window/event/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::window::event::object::object(XEvent const &_event) : event_(_event) {}

XEvent const &awl::backends::x11::window::event::object::get() const { return event_; }

XEvent &awl::backends::x11::window::event::object::get() { return event_; }
