#ifndef AWL_BACKENDS_WINDOWS_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED

#include <awl/backends/windows/cursor/object_unique_ptr.hpp>
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
awl::backends::windows::cursor::object_unique_ptr create_invisible();

}
}
}
}

#endif
