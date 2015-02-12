#ifndef AWL_BACKENDS_WINDOWS_EVENT_GET_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_GET_HPP_INCLUDED

#include <awl/backends/windows/event/message_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

AWL_DETAIL_SYMBOL
awl::backends::windows::event::message const
get();

}
}
}
}

#endif
