#ifndef AWL_BACKENDS_WINDOWS_EVENT_PEEK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_PEEK_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/optional_message.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

AWL_DETAIL_SYMBOL
awl::backends::windows::event::optional_message
peek(
	HWND
);

}
}
}
}

#endif
