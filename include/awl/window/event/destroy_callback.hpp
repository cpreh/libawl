#ifndef AWL_WINDOW_EVENT_DESTROY_CALLBACK_HPP_INCLUDED
#define AWL_WINDOW_EVENT_DESTROY_CALLBACK_HPP_INCLUDED

#include <awl/window/event/destroy_function.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef
fcppt::function<
	awl::window::event::destroy_function
>
destroy_callback;

}
}
}

#endif
