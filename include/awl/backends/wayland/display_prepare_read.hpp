#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_PREPARE_READ_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_PREPARE_READ_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/preprocessor/warn_unused_result.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

AWL_DETAIL_SYMBOL
bool
display_prepare_read(
	awl::backends::wayland::display const &
)
noexcept(true)
FCPPT_PP_WARN_UNUSED_RESULT;

}
}
}

#endif
