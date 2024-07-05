#ifndef AWL_BACKENDS_WINDOWS_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

class AWL_DETAIL_CLASS_SYMBOL object : public awl::cursor::object
{
  FCPPT_NONCOPYABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  AWL_DETAIL_SYMBOL
  virtual ~object();

  virtual HCURSOR get() const = 0;
};

}
}
}
}

#endif
