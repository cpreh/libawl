#ifndef AWL_BACKENDS_X11_WINDOW_BASE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_BASE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/base_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl::backends::x11::window
{

using base_unique_ptr = fcppt::unique_ptr<awl::backends::x11::window::base>;

}

#endif
