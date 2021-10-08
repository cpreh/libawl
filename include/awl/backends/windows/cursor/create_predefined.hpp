#ifndef AWL_BACKENDS_WINDOWS_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED

#include <awl/backends/windows/cursor/object_unique_ptr.hpp>
#include <awl/cursor/type_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

AWL_DETAIL_SYMBOL
awl::backends::windows::cursor::object_unique_ptr create_predefined(awl::cursor::type);

}
}
}
}

#endif
