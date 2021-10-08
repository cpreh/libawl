#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual/get_info.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <awl/backends/x11/visual/mask.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::visual::info_unique_ptr awl::backends::x11::visual::get_info(
    awl::backends::x11::display const &_display,
    awl::backends::x11::visual::mask const _mask,
    XVisualInfo const &_info)
{
  int number_of_items{0};

  awl::backends::x11::visual::info_unique_ptr ret(::XGetVisualInfo(
      _display.get(),
      _mask.get(),
      // libX11 only reads this struct
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
      &const_cast<XVisualInfo &>(_info),
      &number_of_items));

  if (ret.get_pointer() == nullptr)
  {
    throw awl::exception{FCPPT_TEXT("Couldn't get XVisualInfo structure for Visual")};
  }

  return ret;
}
