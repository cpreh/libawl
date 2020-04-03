#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/cursor/convert_predefined.hpp>
#include <awl/backends/x11/cursor/create_predefined.hpp>
#include <awl/backends/x11/cursor/holder.hpp>
#include <awl/backends/x11/cursor/load_font.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/cursor/object_unique_ptr.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/make_unique_ptr.hpp>


awl::backends::x11::cursor::object_unique_ptr
awl::backends::x11::cursor::create_predefined(
	awl::backends::x11::display_ref const _display,
	awl::cursor::type const _type
)
{
	return
		fcppt::make_unique_ptr<
			awl::backends::x11::cursor::object
		>(
			awl::backends::x11::cursor::load_font(
				_display,
				awl::backends::x11::cursor::convert_predefined(
					_type
				)
			)
		);
}
