#ifndef AWL_WINDOW_EVENT_SHOW_CALLBACK_HPP_INCLUDED
#define AWL_WINDOW_EVENT_SHOW_CALLBACK_HPP_INCLUDED

#include <awl/window/event/show_function.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef
fcppt::function<
	awl::window::event::show_function
>
show_callback;

}
}
}

#endif
