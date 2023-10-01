#ifndef AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/window/holder_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11::window
{

class holder
{
  FCPPT_NONMOVABLE(holder);

public:
  holder(awl::backends::x11::display_ref, Window);

  ~holder();

  void destroy();

  [[nodiscard]] bool destroyed() const;

  [[nodiscard]] Window get() const;

private:
  void do_destroy();

  awl::backends::x11::display_ref const display_;

  Window const window_;

  bool destroyed_; // NOLINT(cppcoreguidelines-use-default-member-init)
};

}

#endif
