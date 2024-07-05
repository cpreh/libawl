#ifndef AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11
{

class colormap
{
  FCPPT_NONMOVABLE(colormap);

public:
  AWL_DETAIL_SYMBOL
  colormap(
      awl::backends::x11::display_ref,
      awl::backends::x11::screen,
      awl::backends::x11::visual::object const &);

  AWL_DETAIL_SYMBOL
  ~colormap();

  AWL_DETAIL_SYMBOL
  Colormap &get();

  [[nodiscard]] AWL_DETAIL_SYMBOL Colormap const &get() const;

private:
  awl::backends::x11::display_ref const display_;

  Colormap colormap_;
};

}

#endif
