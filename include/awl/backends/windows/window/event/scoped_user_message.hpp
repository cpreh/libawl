#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_SCOPED_USER_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_SCOPED_USER_MESSAGE_HPP_INCLUDED

#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/backends/windows/window/event/scoped_user_message_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

class scoped_user_message
{
	FCPPT_NONCOPYABLE(
		scoped_user_message
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	scoped_user_message(
		awl::backends::windows::window::event::processor &
	);

	AWL_DETAIL_SYMBOL
	~scoped_user_message();

	AWL_DETAIL_SYMBOL
	awl::backends::windows::event::type const
	type() const;
private:
	awl::backends::windows::window::event::processor &processor_;

	awl::backends::windows::event::type const type_;
};

}
}
}
}
}

#endif
