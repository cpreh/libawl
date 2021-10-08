#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_BASE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_BASE_HPP_INCLUDED

#include <awl/backends/windows/system/event/base_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL base : public awl::event::base
{
  FCPPT_NONCOPYABLE(base);

public:
  AWL_DETAIL_SYMBOL
  base();

  AWL_DETAIL_SYMBOL
  ~base() override;
};

}
}
}
}
}

#endif
