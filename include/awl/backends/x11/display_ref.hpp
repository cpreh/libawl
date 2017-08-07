#ifndef AWL_BACKENDS_X11_DISPLAY_REF_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_REF_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

typedef
fcppt::reference<
	awl::backends::x11::display
>
display_ref;

}
}
}

#endif
