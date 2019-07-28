#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/change_property.hpp>
#include <awl/backends/x11/window/property.hpp>
#include <awl/backends/x11/window/property_data.hpp>
#include <awl/backends/x11/window/property_mode.hpp>
#include <awl/backends/x11/window/property_type.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace
{

int
convert_mode(
	awl::backends::x11::window::property_mode const _type
)
{
	switch(
		_type
	)
	{
	case awl::backends::x11::window::property_mode::replace:
		return
			PropModeReplace;
	case awl::backends::x11::window::property_mode::prepend:
		return
			PropModePrepend;
	case awl::backends::x11::window::property_mode::append:
		return
			PropModeAppend;
	}

	FCPPT_ASSERT_UNREACHABLE;
}

template<
	typename Type
>
void
change_property_impl(
	awl::backends::x11::window::base const &_window,
	awl::backends::x11::window::property const _name,
	awl::backends::x11::window::property_type const _type,
	awl::backends::x11::window::property_mode const _mode,
	awl::backends::x11::window::basic_property_data<
		Type
	> const _data
)
{
	// Always returns 1
	XChangeProperty(
		_window.display().get(),
		_window.get(),
		_name.get().get(),
		_type.get().get(),
		std::numeric_limits<
			Type
		>::digits,
		convert_mode(
			_mode
		),
		fcppt::cast::to_char_ptr<
			unsigned char const *
		>(
			_data.begin()
		),
		fcppt::cast::size<
			int
		>(
			fcppt::cast::to_signed(
				fcppt::range::size(
					_data
				)
			)
		)
	);
}

}

void
awl::backends::x11::window::change_property(
	awl::backends::x11::window::base const &_window,
	awl::backends::x11::window::property const _name,
	awl::backends::x11::window::property_type const _type,
	awl::backends::x11::window::property_mode const _mode,
	awl::backends::x11::window::property_data const &_data_variant
)
{
	fcppt::variant::apply(
		[
			&_window,
			_name,
			_type,
			_mode
		](
			auto const &_data
		)
		{
			change_property_impl(
				_window,
				_name,
				_type,
				_mode,
				_data
			);
		},
		_data_variant
	);
}
