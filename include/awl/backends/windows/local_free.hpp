#ifndef AWL_BACKENDS_WINDOWS_LOCAL_FREE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_LOCAL_FREE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

AWL_DETAIL_SYMBOL
void local_free(HLOCAL);

}
}
}

#endif
