#ifndef AWL_BACKENDS_WINDOWS_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/visual/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace visual
{

class object : public awl::visual::object
{
  FCPPT_NONCOPYABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  AWL_DETAIL_SYMBOL
  ~object() override;

  virtual void apply(HWND) const = 0;
};

}
}
}
}

#endif
