#ifndef AWL_BACKENDS_X11_WINDOW_PROPERTY_MODE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_PROPERTY_MODE_HPP_INCLUDED

#include <awl/backends/x11/window/property_mode_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

enum class property_mode
{
	replace,
	prepend,
	append
};

}
}
}
}

#endif
