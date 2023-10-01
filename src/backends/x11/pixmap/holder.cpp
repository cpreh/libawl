#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/pixmap/holder.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::pixmap::holder::holder(
    awl::backends::x11::display_ref const _display, Pixmap const _pixmap)
    : display_(_display), pixmap_(_pixmap)
{
}

awl::backends::x11::pixmap::holder::~holder() { ::XFreePixmap(display_.get().get(), pixmap_); }

Pixmap awl::backends::x11::pixmap::holder::get() const { return pixmap_; }
