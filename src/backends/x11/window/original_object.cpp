#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/sync.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref.hpp>
#include <awl/backends/x11/window/create.hpp>
#include <awl/backends/x11/window/get_geometry.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/backends/x11/window/rect.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>
#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/static_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::original_object::original_object(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen,
	awl::backends::x11::system::event::original_processor &_system_processor,
	awl::window::parameters const &_params
)
:
	awl::backends::x11::window::object(),
	awl::window::object(),
	display_(
		_display
	),
	screen_(
		_screen
	),
	visual_(
		fcppt::cast::static_downcast<
			awl::backends::x11::visual::object const &
		>(
			_params.visual()
		)
	),
	colormap_(
		display_,
		_screen,
		visual_
	),
	hints_(),
	class_hint_{
		fcppt::optional::apply(
			[](
				fcppt::string const &_title,
				fcppt::string const &_class_name
			){
				return
					fcppt::make_unique_ptr<
						awl::backends::x11::window::original_class_hint
					>(
						awl::backends::x11::window::class_hint{
							awl::backends::x11::window::class_hint::res_name_type{
								fcppt::to_std_string(
									_title
								)
							},
							awl::backends::x11::window::class_hint::res_class_type{
								fcppt::to_std_string(
									_class_name
								)
							}
						}
					);
			},
			_params.title(),
			_params.class_name()
		)
	},
	window_(
		display_,
		awl::backends::x11::window::create(
			_params.size(),
			display_,
			screen_,
			colormap_,
			visual_,
			fcppt::optional::static_cast_<
				awl::backends::x11::cursor::object const
			>(
				_params.cursor()
			)
		)
	),
	processor_{
		fcppt::unique_ptr_to_base<
			awl::backends::x11::window::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::event::original_processor
			>(
				*this
			)
		)
	},
	scoped_processor_{
		_system_processor,
		*this,
		*processor_
	}
{
	// always returns 1
	::XSetWMHints(
		display_.get(),
		window_.get(),
		hints_.get()
	);

	fcppt::optional::maybe_void(
		class_hint_,
		[
			this
		](
			original_class_hint_unique_ptr const &_class_hint
		)
		{
			// always returns 1
			::XSetClassHint(
				display_.get(),
				window_.get(),
				_class_hint->get()
			);
		}
	);

	fcppt::optional::maybe_void(
		_params.title(),
		[
			this
		](
			fcppt::string const &_title
		)
		{
			// always returns 1
			::XStoreName(
				display_.get(),
				window_.get(),
				fcppt::to_std_string(
					_title
				).c_str()
			);
		}
	);
}

awl::backends::x11::window::original_object::~original_object()
{
}

void
awl::backends::x11::window::original_object::show()
{
	// always returns 1
	::XMapWindow(
		this->display().get(),
		this->get()
	);

	awl::backends::x11::sync(
		this->display(),
		awl::backends::x11::discard(
			false
		)
	);
}

awl::window::dim
awl::backends::x11::window::original_object::size() const
{
	return
		fcppt::math::dim::to_unsigned(
			this->rect().size()
		);
}

awl::visual::object const &
awl::backends::x11::window::original_object::visual() const
{
	return
		this->x11_visual();
}

awl::window::event::processor &
awl::backends::x11::window::original_object::processor()
{
	return
		*processor_;
}

bool
awl::backends::x11::window::original_object::destroyed() const
{
	return
		window_.destroyed();
}

awl::backends::x11::display &
awl::backends::x11::window::original_object::display() const
{
	return
		display_;
}

awl::backends::x11::screen
awl::backends::x11::window::original_object::screen() const
{
	return
		screen_;
}

awl::backends::x11::visual::object const &
awl::backends::x11::window::original_object::x11_visual() const
{
	return
		visual_;
}

awl::backends::x11::window::rect
awl::backends::x11::window::original_object::rect() const
{
	return
		awl::backends::x11::window::get_geometry(
			*this
		);
}

Window
awl::backends::x11::window::original_object::get() const
{
	return
		window_.get();
}

awl::backends::x11::window::const_optional_class_hint_ref
awl::backends::x11::window::original_object::class_hint() const
{
	return
		fcppt::optional::map(
			class_hint_,
			[](
				original_class_hint_unique_ptr const &_class_hint
			)
			{
				return
					fcppt::make_cref(
						_class_hint->hint()
					);
			}
		);
}

void
awl::backends::x11::window::original_object::destroy()
{
	window_.destroy();
}
