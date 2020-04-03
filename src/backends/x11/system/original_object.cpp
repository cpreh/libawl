#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/create_invisible.hpp>
#include <awl/backends/x11/cursor/create_predefined.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/original_object.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/visual/default.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type.hpp>
#include <awl/cursor/type.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/log/context_reference.hpp>
#include <fcppt/optional/maybe.hpp>


awl::backends::x11::system::original_object::original_object(
	fcppt::log::context_reference
)
:
	awl::backends::x11::system::object(),
	display_(),
	screen_{
		awl::backends::x11::default_screen(
			this->get_display()
		)
	},
	processor_(
		fcppt::make_unique_ptr<
			awl::backends::x11::system::event::original_processor
		>(
			this->get_display()
		)
	)
{
}

awl::backends::x11::system::original_object::~original_object()
= default;

awl::window::object_unique_ptr
awl::backends::x11::system::original_object::create_window(
	awl::window::parameters const &_parameters
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::window::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::original_object
			>(
				this->display(),
				screen_,
				fcppt::make_ref(
					*processor_
				),
				_parameters
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
				this->display(),
				screen_
			)
		);
}

awl::cursor::object_unique_ptr
awl::backends::x11::system::original_object::create_cursor(
	awl::cursor::optional_type const &_optional_type
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::cursor::object
		>(
			fcppt::optional::maybe(
				_optional_type,
				[
					this
				]{
					return
						awl::backends::x11::cursor::create_invisible(
							this->display()
						);
				},
				[
					this
				](
					awl::cursor::type const _type
				)
				{
					return
						awl::backends::x11::cursor::create_predefined(
							this->display(),
							_type
						);
				}
			)
		);
}

awl::backends::x11::display_ref
awl::backends::x11::system::original_object::display()
{
	return
		this->get_display();
}

awl::backends::x11::screen
awl::backends::x11::system::original_object::screen() const
{
	return
		screen_;
}

awl::backends::x11::display_ref
awl::backends::x11::system::original_object::get_display()
{
	return
		fcppt::reference_to_base<
			awl::backends::x11::display
		>(
			fcppt::make_ref(
				display_
			)
		);
}
