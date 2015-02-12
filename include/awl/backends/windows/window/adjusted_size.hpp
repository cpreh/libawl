#ifndef AWL_BACKENDS_WINDOWS_WINDOW_ADJUSTED_SIZE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_ADJUSTED_SIZE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/signed_dim.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/optional_dim_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

AWL_DETAIL_SYMBOL
awl::backends::windows::window::signed_dim const
adjusted_size(
	awl::window::optional_dim const &,
	DWORD flags
);

}
}
}
}

#endif
