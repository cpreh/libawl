#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/const_optional_object_ref.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/create.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_pos.hpp>
#include <awl/window/pos.hpp>
#include <awl/window/size.hpp>
#include <awl/window/unit.hpp>
#include <fcppt/const.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


Window
awl::backends::x11::window::create(
	awl::window::optional_pos const &_position,
	awl::window::optional_dim const &_dim,
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen,
	awl::backends::x11::colormap const &_colormap,
	awl::backends::x11::visual::object const &_visual,
	awl::backends::x11::cursor::const_optional_object_ref const &_cursor
)
{
	unsigned long value_mask(
		CWColormap
		|
		CWBorderPixel
		|
		CWEventMask
	);

	XSetWindowAttributes swa;

	swa.colormap = _colormap.get();

	swa.border_pixel = 0;

	swa.event_mask = StructureNotifyMask | FocusChangeMask;

	fcppt::optional::maybe_void(
		_cursor,
		[
			&swa,
			&value_mask
		](
			awl::backends::x11::cursor::object const &_opt_cursor
		)
		{
			swa.cursor = _opt_cursor.get();

			value_mask |= CWCursor;
		}
	);

	auto const position_default(
		fcppt::const_(
			fcppt::literal<
				awl::window::unit
			>(
				0
			)
		)
	);

	auto const dim_default(
		fcppt::const_(
			fcppt::literal<
				awl::window::size
			>(
				500
			)
		)
	);

	// always returns a handle
	return
		::XCreateWindow(
			_display.get(),
			::XRootWindow(
				_display.get(),
				_screen.get()
			),
			fcppt::optional::maybe(
				_position,
				position_default,
				[](
					awl::window::pos const _pos
				)
				{
					return
						_pos.x();
				}
			),
			fcppt::optional::maybe(
				_position,
				position_default,
				[](
					awl::window::pos const _pos
				)
				{
					return
						_pos.y();
				}
			),
			fcppt::optional::maybe(
				_dim,
				dim_default,
				[](
					awl::window::dim const _d
				)
				{
					return
						_d.w();
				}
			),
			fcppt::optional::maybe(
				_dim,
				dim_default,
				[](
					awl::window::dim const _d
				)
				{
					return
						_d.h();
				}
			),
			// border_width
			0,
			_visual.depth(),
			InputOutput,
			_visual.get(),
			value_mask,
			&swa
		);
}
