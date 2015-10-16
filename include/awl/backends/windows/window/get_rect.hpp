#ifndef AWL_BACKENDS_WINDOWS_WINDOW_GET_RECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_GET_RECT_HPP_INCLUDED

#include <awl/backends/windows/optional_rect.hpp>
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
awl::backends::windows::optional_rect
get_rect(
	awl::backends::windows::window::object const &
);

}
}
}
}

#endif
