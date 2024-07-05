#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_GENERIC_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_GENERIC_HPP_INCLUDED

#include <awl/backends/windows/system/event/base.hpp>
#include <awl/backends/windows/system/event/generic_fwd.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL generic : public awl::backends::windows::system::event::base
{
  FCPPT_NONCOPYABLE(generic);

public:
  AWL_DETAIL_SYMBOL
  explicit generic(awl::backends::windows::system::event::object const &);

  AWL_DETAIL_SYMBOL
  ~generic() override;

  AWL_DETAIL_SYMBOL
  awl::backends::windows::system::event::object const &get() const;

private:
  awl::backends::windows::system::event::object const event_;
};

}
}
}
}
}

#endif
