#ifndef AWL_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::window
{

class AWL_DETAIL_CLASS_SYMBOL object
{
  FCPPT_NONMOVABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  virtual void show() = 0;

  [[nodiscard]] virtual awl::window::dim size() const = 0;

  [[nodiscard]] virtual awl::visual::object const &visual() const = 0;

  AWL_DETAIL_SYMBOL
  virtual ~object();
};

}

#endif
