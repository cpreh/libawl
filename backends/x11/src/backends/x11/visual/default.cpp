#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/create_info.hpp>
#include <awl/backends/x11/visual/default.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/visual/wrapped.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::visual::object_unique_ptr awl::backends::x11::visual::default_(
    awl::backends::x11::display_ref const _display, awl::backends::x11::screen const _screen)
{
  Visual const *const visual(::XDefaultVisual(_display.get().get(), _screen.get()));

  if (visual == nullptr)
  {
    throw awl::exception{FCPPT_TEXT("XDefaultVisual failed")};
  }

  return fcppt::unique_ptr_to_base<awl::backends::x11::visual::object>(
      fcppt::make_unique_ptr<awl::backends::x11::visual::wrapped>(
          awl::backends::x11::visual::create_info(_display.get(), *visual)));
}
