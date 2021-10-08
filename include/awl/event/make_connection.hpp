#ifndef AWL_EVENT_MAKE_CONNECTION_HPP_INCLUDED
#define AWL_EVENT_MAKE_CONNECTION_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>

namespace awl::event
{

AWL_DETAIL_SYMBOL
awl::event::connection_unique_ptr make_connection(awl::event::connection_function &&);

}

#endif
