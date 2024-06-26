#ifndef AWL_BACKENDS_X11_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/Xutil.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::x11::visual
{

class AWL_DETAIL_CLASS_SYMBOL object : public awl::visual::object
{
  FCPPT_NONMOVABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  AWL_DETAIL_SYMBOL
  ~object() override;

  [[nodiscard]] virtual Visual *get() const = 0;

  [[nodiscard]] virtual XVisualInfo *info() const = 0;

  [[nodiscard]] virtual int depth() const = 0;
};

}

#endif
