#ifndef AWL_BACKENDS_WINDOWS_WINDOW_HAS_FOCUS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_HAS_FOCUS_HPP_INCLUDED

#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

AWL_DETAIL_SYMBOL
bool has_focus(awl::backends::windows::window::object const &);

}
}
}
}

#endif
