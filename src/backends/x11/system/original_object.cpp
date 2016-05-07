#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/create_invisible.hpp>
#include <awl/backends/x11/cursor/create_predefined.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/original_object.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/visual/default.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/type.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


awl::backends::x11::system::original_object::original_object()
:
	awl::backends::x11::system::object(),
	display_(),
	screen_(
		awl::backends::x11::default_screen(
			display_
		)
	),
	processor_(
		fcppt::unique_ptr_to_base<
			awl::system::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::system::event::original_processor
			>(
				display_
			)
		)
	)
{
}

awl::backends::x11::system::original_object::~original_object()
{
}

awl::window::object_unique_ptr
awl::backends::x11::system::original_object::create_window(
	awl::window::parameters const &_param
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::window::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::original_object
			>(
				display_,
				screen_,
				_param
			)
		);
}

awl::system::event::processor &
awl::backends::x11::system::original_object::processor()
{
	return
		*processor_;
}

awl::visual::object_unique_ptr
awl::backends::x11::system::original_object::default_visual()
{
	return
		fcppt::unique_ptr_to_base<
			awl::visual::object
		>(
			awl::backends::x11::visual::default_(
				display_,
				screen_
			)
		);
}

awl::cursor::object_unique_ptr
awl::backends::x11::system::original_object::create_cursor(
	awl::cursor::type const _type
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::cursor::object
		>(
			_type
			==
			awl::cursor::type::invisible
			?
				awl::backends::x11::cursor::create_invisible(
					display_
				)
			:
				awl::backends::x11::cursor::create_predefined(
					display_,
					_type
				)
		);
}

awl::backends::x11::display &
awl::backends::x11::system::original_object::display()
{
	return
		display_;
}

awl::backends::x11::screen
awl::backends::x11::system::original_object::screen() const
{
	return
		screen_;
}
