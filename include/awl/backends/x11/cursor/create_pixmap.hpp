#ifndef AWL_BACKENDS_X11_CURSOR_CREATE_PIXMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CREATE_PIXMAP_HPP_INCLUDED

#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/cursor/background_color.hpp>
#include <awl/backends/x11/cursor/dest_pixmap.hpp>
#include <awl/backends/x11/cursor/foreground_color.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/source_pixmap.hpp>
#include <awl/cursor/hotspot_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::cursor
{

AWL_DETAIL_SYMBOL
awl::backends::x11::cursor::holder_unique_ptr create_pixmap(
    awl::backends::x11::display_ref,
    awl::backends::x11::cursor::source_pixmap const &,
    awl::backends::x11::cursor::dest_pixmap const &,
    awl::backends::x11::cursor::foreground_color const &,
    awl::backends::x11::cursor::background_color const &,
    awl::cursor::hotspot const &);

}

#endif
