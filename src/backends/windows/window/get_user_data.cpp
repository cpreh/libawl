#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/get_long_ptr.hpp>
#include <awl/backends/windows/window/get_user_data.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/optional_user_data_ref.hpp>
#include <awl/backends/windows/window/user_data_fwd.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/optional/make_if.hpp>

awl::backends::windows::window::optional_user_data_ref
awl::backends::windows::window::get_user_data(HWND const _hwnd)
{
  LONG_PTR const result{awl::backends::windows::window::get_long_ptr(_hwnd, GWLP_USERDATA)};

  return fcppt::optional::make_if(
      result != fcppt::literal<LONG_PTR>(0),
      [result]
      {
        return fcppt::make_cref(
            *reinterpret_cast<awl::backends::windows::window::user_data const *>(result));
      });
}
