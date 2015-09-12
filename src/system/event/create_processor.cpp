#include <awl/system/event/create_processor.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <fcppt/cast/static_downcast.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <fcppt/cast/static_downcast.hpp>
#elif defined(AWL_COCOA_BACKEND)
#include <awl/backends/cocoa/system/event/create_processor.hpp>
#include <awl/system/event/processor.hpp>
#endif
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


awl::system::event::processor_unique_ptr
awl::system::event::create_processor(
	awl::system::object &_system
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::system::event::processor
		>(
#if defined(AWL_X11_BACKEND)
			fcppt::make_unique_ptr<
				backends::x11::system::event::original_processor
			>(
				fcppt::cast::static_downcast<
					backends::x11::system::object &
				>(
					_system
				)
			)
#elif defined(AWL_WINDOWS_BACKEND)
			fcppt::make_unique_ptr<
				backends::windows::system::event::original_processor
			>(
				fcppt::cast::static_downcast<
					backends::windows::system::object &
				>(
					_system
				)
			)
#elif defined(AWL_COCOA_BACKEND)
			backends::cocoa::system::event::create_processor(
				_system
			)
#endif
		);
}
