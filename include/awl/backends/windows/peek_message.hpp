#ifndef AWL_BACKENDS_WINDOWS_PEEK_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_PEEK_MESSAGE_HPP_INCLUDED

#include <awl/backends/windows/optional_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

AWL_DETAIL_SYMBOL
awl::backends::windows::optional_message
peek_message(
	HWND
);

}
}
}

#endif
