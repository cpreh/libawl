#ifndef AWL_BACKENDS_WINDOWS_SCOPED_LOCAL_MEMORY_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SCOPED_LOCAL_MEMORY_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class scoped_local_memory
{
  FCPPT_NONCOPYABLE(scoped_local_memory);

public:
  AWL_DETAIL_SYMBOL
  explicit scoped_local_memory(HLOCAL);

  AWL_DETAIL_SYMBOL
  ~scoped_local_memory();

private:
  HLOCAL const memory_;
};

}
}
}

#endif
