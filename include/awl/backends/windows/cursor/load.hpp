#ifndef AWL_BACKENDS_WINDOWS_CURSOR_LOAD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_LOAD_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/char_type.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

AWL_DETAIL_SYMBOL
HCURSOR
load(
	fcppt::char_type const *
);

}
}
}
}

#endif
