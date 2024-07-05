#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/system/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{

class object : public awl::system::object
{
  FCPPT_NONMOVABLE(object);

protected:
  AWL_DETAIL_SYMBOL
  object();

public:
  AWL_DETAIL_SYMBOL
  ~object() override;
};

}
}
}
}

#endif
