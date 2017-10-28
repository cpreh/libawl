#ifndef AWL_BACKENDS_WINDOWS_WINDOW_SET_LONG_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_SET_LONG_PTR_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
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
void
set_long_ptr(
	HWND,
	int,
	LONG_PTR
);

}
}
}
}

#endif
