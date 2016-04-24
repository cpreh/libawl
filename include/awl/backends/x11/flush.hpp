#ifndef AWL_BACKENDS_X11_FLUSH_HPP_INCLUDED
#define AWL_BACKENDS_X11_FLUSH_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

AWL_DETAIL_SYMBOL
void
flush(
	awl::backends::x11::display const &
);

}
}
}

#endif
