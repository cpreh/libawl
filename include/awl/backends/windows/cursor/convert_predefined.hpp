#ifndef AWL_BACKENDS_WINDOWS_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED

#include <awl/cursor/type_fwd.hpp>
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
fcppt::char_type const *convert_predefined(awl::cursor::type);

}
}
}
}

#endif
