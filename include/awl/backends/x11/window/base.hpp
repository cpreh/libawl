#ifndef AWL_BACKENDS_X11_WINDOW_BASE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_BASE_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/base_fwd.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref_fwd.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/object.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11::window
{

class AWL_DETAIL_CLASS_SYMBOL base : public awl::window::object
{
  FCPPT_NONMOVABLE(base);

protected:
  AWL_DETAIL_SYMBOL
  base();

public:
  AWL_DETAIL_SYMBOL
  ~base() override;

  [[nodiscard]] virtual bool destroyed() const = 0;

  [[nodiscard]] virtual awl::backends::x11::display_ref display() const = 0;

  [[nodiscard]] virtual awl::backends::x11::screen screen() const = 0;

  [[nodiscard]] virtual awl::backends::x11::visual::object const &x11_visual() const = 0;

  [[nodiscard]] virtual awl::backends::x11::window::rect rect() const = 0;

  [[nodiscard]] virtual Window get() const = 0;

  [[nodiscard]] virtual awl::backends::x11::window::const_optional_class_hint_ref
  class_hint() const = 0;

  AWL_DETAIL_SYMBOL
  void show() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::window::dim size() const override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::visual::object const &visual() const override;
};

}

#endif
