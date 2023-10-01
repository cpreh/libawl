#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/cursor/background_color.hpp>
#include <awl/backends/x11/cursor/create_invisible.hpp>
#include <awl/backends/x11/cursor/create_pixmap.hpp>
#include <awl/backends/x11/cursor/dest_pixmap.hpp>
#include <awl/backends/x11/cursor/foreground_color.hpp>
#include <awl/backends/x11/cursor/holder.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/cursor/object_unique_ptr.hpp>
#include <awl/backends/x11/cursor/source_pixmap.hpp>
#include <awl/backends/x11/pixmap/create_from_data.hpp>
#include <awl/backends/x11/pixmap/dim.hpp>
#include <awl/backends/x11/pixmap/holder.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/pixmap/holder_unique_ptr.hpp>
#include <awl/backends/x11/pixmap/size.hpp>
#include <awl/backends/x11/window/object.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/window/root.hpp>
#include <awl/cursor/hotspot.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::cursor::object_unique_ptr
awl::backends::x11::cursor::create_invisible(awl::backends::x11::display_ref const _display)
{
  awl::backends::x11::pixmap::size const size{8};

  auto const bm_no_data{
      fcppt::array::init<fcppt::array::object<char, size * size / 8>>([](auto) { return '\0'; })};

  awl::backends::x11::pixmap::holder_unique_ptr const pixmap(
      awl::backends::x11::pixmap::create_from_data(
          *awl::backends::x11::window::root(_display, awl::backends::x11::default_screen(_display)),
          awl::backends::x11::pixmap::dim(size, size),
          bm_no_data.data()));

  XColor const black{0, 0, 0, 0, 0, 0};

  return fcppt::make_unique_ptr<awl::backends::x11::cursor::object>(
      awl::backends::x11::cursor::create_pixmap(
          _display,
          awl::backends::x11::cursor::source_pixmap(fcppt::make_cref(*pixmap)),
          awl::backends::x11::cursor::dest_pixmap(fcppt::make_cref(*pixmap)),
          awl::backends::x11::cursor::foreground_color(black),
          awl::backends::x11::cursor::background_color(black),
          awl::cursor::hotspot(0U, 0U)));
}
