#include <awl/backends/x11/to_x11_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

Bool awl::backends::x11::to_x11_bool(bool const _value) { return _value ? True : False; }
