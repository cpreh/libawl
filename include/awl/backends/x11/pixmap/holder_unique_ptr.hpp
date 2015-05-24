#ifndef AWL_BACKENDS_X11_PIXMAP_HOLDER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_HOLDER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/pixmap/holder_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace pixmap
{

typedef
fcppt::unique_ptr<
	awl::backends::x11::pixmap::holder
>
holder_unique_ptr;

}
}
}
}

#endif
