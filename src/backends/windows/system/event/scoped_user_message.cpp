#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/system/event/scoped_user_message.hpp>


awl::backends::windows::system::event::scoped_user_message::scoped_user_message(
	awl::backends::windows::system::event::processor &_processor
)
:
	processor_(
		_processor
	),
	type_(
		_processor.allocate_user_message()
	)
{
}

awl::backends::windows::system::event::scoped_user_message::~scoped_user_message()
{
	processor_.free_user_message(
		type_
	);
}

awl::backends::windows::message_type
awl::backends::windows::system::event::scoped_user_message::type() const
{
	return
		type_;
}
