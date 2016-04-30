#ifndef AWL_BACKENDS_WINDOWS_POST_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_POST_MESSAGE_HPP_INCLUDED

#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

AWL_DETAIL_SYMBOL
void
post_message(
	HWND,
	awl::backends::windows::message_type,
	awl::backends::windows::wparam,
	awl::backends::windows::lparam
);

}
}
}

#endif
