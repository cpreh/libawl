#ifndef AWL_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::visual
{

class AWL_DETAIL_CLASS_SYMBOL object
{
  FCPPT_NONMOVABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  AWL_DETAIL_SYMBOL
  virtual ~object();
};

}

#endif
