#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_MAKE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_MAKE_HPP_INCLUDED

#include <awl/backends/x11/window/object_ref.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/event/base_unique_ptr.hpp>

namespace awl::backends::x11::window::event
{

awl::event::base_unique_ptr
make(awl::backends::x11::window::object_ref, awl::backends::x11::window::event::object const &);

}

#endif
