#ifndef AWL_WINDOW_EVENT_DESTROY_HPP_INCLUDED
#define AWL_WINDOW_EVENT_DESTROY_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/destroy_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::window::event
{

class AWL_DETAIL_CLASS_SYMBOL destroy : public awl::window::event::base
{
  FCPPT_NONMOVABLE(destroy);

public:
  AWL_DETAIL_SYMBOL
  explicit destroy(awl::window::reference);

  AWL_DETAIL_SYMBOL
  ~destroy() override;
};

}

#endif
