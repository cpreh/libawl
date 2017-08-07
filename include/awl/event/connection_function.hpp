#ifndef AWL_EVENT_CONNECTION_FUNCTION_HPP_INCLUDED
#define AWL_EVENT_CONNECTION_FUNCTION_HPP_INCLUDED

#include <fcppt/function_impl.hpp>


namespace awl
{
namespace event
{

typedef
fcppt::function<
	void ()
>
connection_function;

}
}

#endif
