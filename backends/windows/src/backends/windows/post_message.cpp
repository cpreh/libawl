#include <awl/exception.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/post_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <fcppt/text.hpp>

void awl::backends::windows::post_message(
    HWND const _hwnd,
    awl::backends::windows::message_type const _msg,
    awl::backends::windows::wparam const _wparam,
    awl::backends::windows::lparam const _lparam)
{
  if (PostMessage(_hwnd, _msg.get(), _wparam.get(), _lparam.get()) == 0)
    throw awl::exception{FCPPT_TEXT("PostMessage() failed!")};
}
