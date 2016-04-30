#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/create_processor.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/processor_unique_ptr.hpp>
#include <awl/backends/windows/window/event/unregister_callback.hpp>
#include <awl/window/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/static_downcast.hpp>


awl::backends::windows::window::event::processor_unique_ptr
awl::backends::windows::window::event::create_processor(
	awl::window::object &_window,
	awl::backends::windows::window::event::unregister_callback const &_unregister
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::backends::windows::window::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::window::event::original_processor
			>(
				fcppt::cast::static_downcast<
					awl::backends::windows::window::object &
				>(
					_window
				),
				_unregister
			)
		);
}
