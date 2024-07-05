#ifndef AWL_BACKENDS_WINDOWS_HAS_LAST_ERROR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_HAS_LAST_ERROR_HPP_INCLUDED

#include <awl/detail/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

AWL_DETAIL_SYMBOL
bool has_last_error();

}
}
}

#endif
