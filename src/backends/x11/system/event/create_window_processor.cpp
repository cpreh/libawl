#include <awl/backends/x11/system/event/create_window_processor.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/processor_unique_ptr.hpp>
#include <awl/backends/x11/window/event/unregister_callback.hpp>
#include <awl/window/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/static_downcast.hpp>


awl::backends::x11::window::event::processor_unique_ptr
awl::backends::x11::system::event::create_window_processor(
	awl::window::object &_window,
	awl::backends::x11::window::event::unregister_callback const _unregister
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::backends::x11::window::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::event::original_processor
			>(
				fcppt::cast::static_downcast<
					awl::backends::x11::window::object &
				>(
					_window
				),
				_unregister
			)
		);
}
