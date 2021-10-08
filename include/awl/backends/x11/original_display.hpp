#ifndef AWL_BACKENDS_X11_ORIGINAL_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_ORIGINAL_DISPLAY_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11
{

class original_display : public awl::backends::x11::display
{
  FCPPT_NONMOVABLE(original_display);

public:
  AWL_DETAIL_SYMBOL
  original_display();

  [[nodiscard]] AWL_DETAIL_SYMBOL Display *get() const override;

  AWL_DETAIL_SYMBOL
  ~original_display() override;

private:
  Display *const ptr_;
};

}

#endif
