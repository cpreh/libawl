#include <awl/exception.hpp>
#include <awl/backends/windows/message_box.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/maybe.hpp>

void awl::backends::windows::message_box(
    awl::backends::windows::window::const_optional_object_ref const &_opt_window,
    fcppt::string const &_text,
    fcppt::string const &_title,
    UINT const _type)
{
  if (::MessageBox(
          fcppt::optional::maybe(
              _opt_window,
              fcppt::const_<HWND>(nullptr),
              [](fcppt::reference<awl::backends::windows::window::object const> const _window)
              { return _window.get().hwnd(); }),
          _text.c_str(),
          _title.c_str(),
          _type) == 0)
    throw awl::exception(FCPPT_TEXT("MessageBox failed: ") + _text);
}
