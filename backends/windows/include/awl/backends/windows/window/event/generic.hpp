#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_GENERIC_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_GENERIC_HPP_INCLUDED

#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/reference.hpp>
#include <awl/backends/windows/window/event/generic_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/base.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL generic : public awl::window::event::base
{
  FCPPT_NONCOPYABLE(generic);

public:
  AWL_DETAIL_SYMBOL
  generic(
      awl::backends::windows::window::reference,
      awl::backends::windows::message_type,
      awl::backends::windows::wparam,
      awl::backends::windows::lparam);

  AWL_DETAIL_SYMBOL
  ~generic() override;

  AWL_DETAIL_SYMBOL
  awl::backends::windows::window::reference get() const;

  AWL_DETAIL_SYMBOL
  awl::backends::windows::message_type type() const;

  AWL_DETAIL_SYMBOL
  awl::backends::windows::wparam wparam() const;

  AWL_DETAIL_SYMBOL
  awl::backends::windows::lparam lparam() const;

private:
  awl::backends::windows::window::reference const window_;

  awl::backends::windows::message_type const type_;

  awl::backends::windows::wparam const wparam_;

  awl::backends::windows::lparam const lparam_;
};

}
}
}
}
}

#endif
