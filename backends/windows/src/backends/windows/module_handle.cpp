#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/text.hpp>

HMODULE
awl::backends::windows::module_handle()
{
  HMODULE const object(::GetModuleHandle(nullptr));

  if (object == nullptr)
    throw awl::exception(FCPPT_TEXT("GetModuleHandle() failed!"));

  return object;
}
