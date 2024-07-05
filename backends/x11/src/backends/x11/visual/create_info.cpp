#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/visual/create_info.hpp>
#include <awl/backends/x11/visual/get_info.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <awl/backends/x11/visual/mask.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::visual::info_unique_ptr awl::backends::x11::visual::create_info(
    awl::backends::x11::display const &_display, Visual const &_visual)
{
  XVisualInfo tpl;

  tpl.visualid = ::XVisualIDFromVisual(
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
      const_cast<Visual *>(&_visual));

  tpl.red_mask = _visual.red_mask;
  tpl.green_mask = _visual.green_mask;
  tpl.blue_mask = _visual.blue_mask;
  tpl.bits_per_rgb = _visual.bits_per_rgb;
  tpl.c_class = _visual.c_class;

  return awl::backends::x11::visual::get_info(
      _display,
      awl::backends::x11::visual::mask{// NOLINTNEXTLINE(hicpp-signed-bitwise)
                                       VisualIDMask | VisualRedMaskMask | VisualGreenMaskMask |
                                       VisualBlueMaskMask | VisualBitsPerRGBMask | VisualClassMask},
      tpl);
}
