#ifndef AWL_BACKENDS_WINDOWS_WINDOW_GET_USER_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_GET_USER_DATA_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/optional_user_data_ref.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

awl::backends::windows::window::optional_user_data_ref
get_user_data(
	HWND
);

}
}
}
}

#endif
