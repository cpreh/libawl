#ifndef AWL_BACKENDS_X11_WINDOW_BASIC_PROPERTY_DATA_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_BASIC_PROPERTY_DATA_FWD_HPP_INCLUDED

#include <fcppt/iterator/range_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

template<
	typename Data
>
using
basic_property_data
=
fcppt::iterator::range<
	Data const *
>;

}
}
}
}

#endif
