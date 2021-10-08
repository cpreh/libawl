#ifndef AWL_BACKENDS_WINDOWS_WINDOW_CLIENT_TO_SCREEN_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_CLIENT_TO_SCREEN_HPP_INCLUDED

#include <awl/backends/windows/optional_point_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
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
awl::backends::windows::optional_point
client_to_screen(awl::backends::windows::window::object const &, POINT const &);

}
}
}
}

#endif
