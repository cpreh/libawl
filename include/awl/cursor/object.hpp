#ifndef AWL_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::cursor
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
