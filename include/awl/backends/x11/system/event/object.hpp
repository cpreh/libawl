#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/system/event/object_fwd.hpp> // IWYU pragma: keep
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::system::event
{

class object
{
public:
  AWL_DETAIL_SYMBOL
  explicit object(XEvent const &);

  [[nodiscard]] AWL_DETAIL_SYMBOL XEvent const &get() const;

  [[nodiscard]] AWL_DETAIL_SYMBOL XEvent &get();

private:
  XEvent event_;
};

}

#endif
