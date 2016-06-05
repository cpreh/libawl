#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/display_roundtrip.hpp>
#include <awl/backends/wayland/cursor/convert_name.hpp>
#include <awl/backends/wayland/cursor/create_invisible.hpp>
#include <awl/backends/wayland/cursor/create_name.hpp>
#include <awl/backends/wayland/cursor/name.hpp>
#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/system/object.hpp>
#include <awl/backends/wayland/system/original_object.hpp>
#include <awl/backends/wayland/system/event/original_processor.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/backends/wayland/visual/null_object.hpp>
#include <awl/backends/wayland/window/original_object.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/type.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/optional/maybe.hpp>


awl::backends::wayland::system::original_object::original_object()
:
	awl::backends::wayland::system::object(),
	display_(),
	processor_{
		fcppt::unique_ptr_to_base<
			awl::backends::wayland::system::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::wayland::system::event::original_processor
			>(
				display_
			)
		)
	},
	cursor_theme_{
		processor_->shm()
	}
{
}

awl::backends::wayland::system::original_object::~original_object()
{
}

awl::window::object_unique_ptr
awl::backends::wayland::system::original_object::create_window(
	awl::window::parameters const &_parameters
)
{
	awl::window::object_unique_ptr result{
		fcppt::unique_ptr_to_base<
			awl::window::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::wayland::window::original_object
			>(
				display_,
				processor_->compositor(),
				processor_->shell(),
				_parameters
			)
		)
	};

	// TODO: Do we need this?
	awl::backends::wayland::display_roundtrip(
		display_
	);

	return
		result;
}

awl::system::event::processor &
awl::backends::wayland::system::original_object::processor()
{
	return
		*processor_;
}

awl::visual::object_unique_ptr
awl::backends::wayland::system::original_object::default_visual()
{
	return
		fcppt::unique_ptr_to_base<
			awl::visual::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::wayland::visual::null_object
			>()
		);
}

awl::cursor::object_unique_ptr
awl::backends::wayland::system::original_object::create_cursor(
	awl::cursor::type const _type
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::cursor::object
		>(
			fcppt::optional::maybe(
				awl::backends::wayland::cursor::convert_name(
					_type
				),
				[]{
					return
						awl::backends::wayland::cursor::create_invisible();
				},
				[
					this
				](
					awl::backends::wayland::cursor::name const &_name
				)
				{
					return
						awl::backends::wayland::cursor::create_name(
							cursor_theme_,
							_name
						);
				}
			)
		);
}

awl::backends::wayland::display &
awl::backends::wayland::system::original_object::display()
{
	return
		display_;
}
