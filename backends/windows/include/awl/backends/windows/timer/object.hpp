#ifndef AWL_BACKENDS_WINDOWS_TIMER_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/timer/object_fwd.hpp>
#include <awl/backends/windows/timer/waitable_unique_ptr.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace timer
{

class AWL_DETAIL_CLASS_SYMBOL object : public awl::timer::object
{
  FCPPT_NONCOPYABLE(object);

public:
  AWL_DETAIL_CLASS_SYMBOL
  object(
      awl::timer::setting const &,
      awl::backends::windows::timer::waitable_unique_ptr &&,
      awl::event::connection_unique_ptr &&);

  AWL_DETAIL_CLASS_SYMBOL
  ~object() override;

private:
  awl::backends::windows::timer::waitable_unique_ptr const timer_;

  awl::event::connection_unique_ptr const connection_;
};

}
}
}
}

#endif
