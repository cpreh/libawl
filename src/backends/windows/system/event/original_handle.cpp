#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/handle_holder.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::system::event::original_handle::original_handle(
	awl::backends::windows::system::event::handle_holder_unique_ptr &&_handle,
	awl::event::connection_unique_ptr &&_connection
)
:
	handle_{
		std::move(
			_handle
		)
	},
	connection_{
		std::move(
			_connection
		)
	}
{
}

awl::backends::windows::system::event::original_handle::~original_handle()
{
}

HANDLE
awl::backends::windows::system::event::original_handle::get() const
{
	return
		handle_->get();
}
