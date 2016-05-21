#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_SCOPED_USER_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_SCOPED_USER_MESSAGE_HPP_INCLUDED

#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/system/event/processor_fwd.hpp>
#include <awl/backends/windows/system/event/scoped_user_message_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


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

class scoped_user_message
{
	FCPPT_NONCOPYABLE(
		scoped_user_message
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	scoped_user_message(
		awl::backends::windows::system::event::processor &
	);

	AWL_DETAIL_SYMBOL
	~scoped_user_message();

	AWL_DETAIL_SYMBOL
	awl::backends::windows::message_type
	type() const;
private:
	awl::backends::windows::system::event::processor &processor_;

	awl::backends::windows::message_type const type_;
};

}
}
}
}
}

#endif
