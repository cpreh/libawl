#ifndef AWL_BACKENDS_X11_WINDOW_HINTS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_HINTS_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::x11::window
{

class hints
{
  FCPPT_NONMOVABLE(hints);

public:
  AWL_DETAIL_SYMBOL
  hints();

  AWL_DETAIL_SYMBOL
  ~hints();

  [[nodiscard]] AWL_DETAIL_SYMBOL XWMHints *get() const;

private:
  XWMHints *const hints_;
};

}

#endif
