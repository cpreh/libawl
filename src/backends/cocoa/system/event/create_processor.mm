#include <awl/backends/cocoa/system/event/create_processor.hpp>
#include <awl/backends/cocoa/system/event/processor.hpp>
#include <fcppt/make_unique_ptr_fcppt.hpp>

awl::system::event::processor_unique_ptr
awl::backends::cocoa::system::event::create_processor(
	awl::system::object &)
{
	return
		awl::system::event::processor_unique_ptr(
			fcppt::make_unique_ptr_fcppt<backends::cocoa::system::event::processor>());
}
