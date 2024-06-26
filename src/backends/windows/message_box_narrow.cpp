#include <awl/exception.hpp>
#include <awl/backends/windows/message_box_narrow.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <fcppt/const.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

void awl::backends::windows::message_box_narrow(
    awl::backends::windows::window::const_optional_object_ref const &_opt_window,
    std::string const &_text,
    std::string const &_title,
    UINT const _type)
{
  if (::MessageBoxA(
          fcppt::optional::maybe(
              _opt_window,
              fcppt::const_<HWND>(nullptr),
              [](fcppt::reference<awl::backends::windows::window::object const> const _window)
              { return _window.get().hwnd(); }),
          _text.c_str(),
          _title.c_str(),
          _type) == 0)
    throw awl::exception(FCPPT_TEXT("MessageBoxA failed: ") + fcppt::from_std_string(_text));
}
