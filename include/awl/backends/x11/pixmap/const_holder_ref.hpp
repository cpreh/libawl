#ifndef AWL_BACKENDS_X11_PIXMAP_CONST_HOLDER_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_CONST_HOLDER_REF_HPP_INCLUDED

#include <awl/backends/x11/pixmap/holder_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace pixmap
{

typedef
fcppt::reference<
	awl::backends::x11::pixmap::holder const
>
const_holder_ref;

}
}
}
}

#endif
