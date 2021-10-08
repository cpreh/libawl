#ifndef AWL_WINDOW_EVENT_BASE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_BASE_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/reference.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::window::event
{

class AWL_DETAIL_CLASS_SYMBOL base : public awl::event::base
{
  FCPPT_NONMOVABLE(base);

public:
  AWL_DETAIL_SYMBOL
  explicit base(awl::window::reference);

  AWL_DETAIL_SYMBOL
  ~base() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::window::object &window() const;

private:
  awl::window::reference const window_;
};

}

#endif
