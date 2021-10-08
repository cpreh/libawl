#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/handle_holder.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>

awl::backends::windows::system::event::handle_holder::handle_holder()
    : handle_(::CreateEvent(NULL, FALSE, FALSE, NULL))
{
  if (handle_ == NULL)
    throw awl::exception{FCPPT_TEXT("CreateEvent() failed!")};
}

awl::backends::windows::system::event::handle_holder::~handle_holder() { ::CloseHandle(handle_); }

HANDLE
awl::backends::windows::system::event::handle_holder::get() const { return handle_; }
