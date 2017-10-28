#ifndef AWL_BACKENDS_WINDOWS_WINDOW_SET_USER_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_SET_USER_DATA_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/reference.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

void
set_user_data(
	HWND,
	awl::backends::windows::window::reference
);

}
}
}
}

#endif
