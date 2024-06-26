#ifndef AWL_BACKENDS_X11_VISUAL_CREATE_INFO_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_CREATE_INFO_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::visual
{

AWL_DETAIL_SYMBOL
awl::backends::x11::visual::info_unique_ptr
create_info(awl::backends::x11::display const &, Visual const &);

}

#endif
