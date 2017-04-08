#ifndef AWL_BACKENDS_WINDOWS_GET_COMMAND_LINE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_GET_COMMAND_LINE_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/char_type.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

// TODO: string_view
AWL_DETAIL_SYMBOL
fcppt::char_type const *
get_command_line()
noexcept;

}
}
}

#endif
