#ifndef AWL_EVENT_BASE_HPP_INCLUDED
#define AWL_EVENT_BASE_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::event
{

class AWL_DETAIL_CLASS_SYMBOL base
{
  FCPPT_NONMOVABLE(base);

protected:
  AWL_DETAIL_SYMBOL
  base();

public:
  AWL_DETAIL_SYMBOL
  virtual ~base();
};

}

#endif
