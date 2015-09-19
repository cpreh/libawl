#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_FILTER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_FILTER_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/preprocessor/warn_unused_result.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

AWL_DETAIL_SYMBOL
bool
filter(
	awl::backends::x11::window::event::object,
	awl::backends::x11::window::object const &
)
FCPPT_PP_WARN_UNUSED_RESULT;

}
}
}
}
}

#endif
