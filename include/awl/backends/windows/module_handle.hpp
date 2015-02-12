#ifndef AWL_BACKENDS_WINDOWS_MODULE_HANDLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MODULE_HANDLE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

AWL_DETAIL_SYMBOL
HMODULE
module_handle();

}
}
}

#endif
