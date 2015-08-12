#ifndef AWL_WINDOW_EVENT_RESIZE_CALLBACK_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_CALLBACK_HPP_INCLUDED

#include <awl/window/event/resize_function.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef
fcppt::function<
	awl::window::event::resize_function
>
resize_callback;

}
}
}

#endif
