#ifndef AWL_BACKENDS_WINDOWS_WINDOW_SCREEN_TO_CLIENT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_SCREEN_TO_CLIENT_HPP_INCLUDED

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
screen_to_client(
	awl::backends::windows::window::object const &,
	POINT const &
);

}
}
}
}

#endif
