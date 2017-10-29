#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_MATCHES_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_MATCHES_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

AWL_DETAIL_SYMBOL
bool
handle_matches(
	awl::event::base const &,
	awl::backends::windows::system::event::handle const &
);

}
}
}
}
}

#endif
