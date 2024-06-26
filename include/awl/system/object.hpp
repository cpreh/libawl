#ifndef AWL_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::system
{

class AWL_DETAIL_CLASS_SYMBOL object
{
  FCPPT_NONMOVABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  virtual awl::window::object_unique_ptr create_window(awl::window::parameters const &) = 0;

  virtual awl::system::event::processor &processor() = 0;

  virtual awl::visual::object_unique_ptr default_visual() = 0;

  virtual awl::cursor::object_unique_ptr create_cursor(awl::cursor::optional_type const &) = 0;

  AWL_DETAIL_SYMBOL
  virtual ~object();
};

}

#endif
