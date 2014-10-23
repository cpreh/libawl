#ifndef AWL_BACKENDS_X11_VISUAL_GET_INFO_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_GET_INFO_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

AWL_DETAIL_SYMBOL
awl::backends::x11::visual::info_unique_ptr
get_info(
	awl::backends::x11::display const &,
	long mask,
	XVisualInfo const &
);

}
}
}
}

#endif
