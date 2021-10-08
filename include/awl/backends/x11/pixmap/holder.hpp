#ifndef AWL_BACKENDS_X11_PIXMAP_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/pixmap/holder_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11::pixmap
{

class holder
{
  FCPPT_NONMOVABLE(holder);

public:
  AWL_DETAIL_SYMBOL
  holder(awl::backends::x11::display_ref, Pixmap);

  AWL_DETAIL_SYMBOL
  ~holder();

  [[nodiscard]] AWL_DETAIL_SYMBOL Pixmap get() const;

private:
  awl::backends::x11::display_ref const display_;

  Pixmap const pixmap_;
};

}

#endif
