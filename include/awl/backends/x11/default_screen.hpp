#ifndef AWL_BACKENDS_X11_DEFAULT_SCREEN_HPP_INCLUDED
#define AWL_BACKENDS_X11_DEFAULT_SCREEN_HPP_INCLUDED

#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/detail/symbol.hpp>


namespace awl::backends::x11
{

AWL_DETAIL_SYMBOL
awl::backends::x11::screen
default_screen(
	awl::backends::x11::display_ref
);

}

#endif
