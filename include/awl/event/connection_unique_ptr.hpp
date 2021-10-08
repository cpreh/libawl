#ifndef AWL_EVENT_CONNECTION_UNIQUE_PTR_HPP_INCLUDED
#define AWL_EVENT_CONNECTION_UNIQUE_PTR_HPP_INCLUDED

#include <awl/event/connection_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl::event
{

using connection_unique_ptr = fcppt::unique_ptr<awl::event::connection>;

}

#endif
