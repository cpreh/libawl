#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/get_input_focus.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/original_object.hpp>
#include <awl/backends/x11/visual/default.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/object_unique_ptr.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/optional_object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::original_object::original_object()
:
	display_(),
	screen_(
		awl::backends::x11::default_screen(
			display_
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

awl::window::optional_object_unique_ptr
awl::backends::x11::system::original_object::focus_window()
{
	return
		fcppt::optional_bind_construct(
			awl::backends::x11::get_input_focus(
				display_,
				screen_
			),
			[](
				awl::backends::x11::window::object_unique_ptr &&_window
			)
			{
				return
					fcppt::unique_ptr_to_base<
						awl::window::object
					>(
						std::move(
							_window
						)
					);
			}
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
