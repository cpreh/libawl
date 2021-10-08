#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_WM_PROTOCOLS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_WM_PROTOCOLS_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11::window::event
{

class wm_protocols
{
  FCPPT_NONMOVABLE(wm_protocols);

public:
  wm_protocols(
      awl::backends::x11::window::base const &,
      awl::backends::x11::window::event::atom_vector const &);

  ~wm_protocols(); // NOLINT(performance-trivially-destructible)
private:
  // TODO(philipp): unset what was given here again!
};

}

#endif
