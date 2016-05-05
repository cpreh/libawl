#include <awl/exception.hpp>
#include <awl/backends/wayland/cursor/name.hpp>
#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/optional.hpp>
#include <awl/backends/wayland/cursor/predefined.hpp>
#include <awl/backends/wayland/cursor/theme.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-cursor.h>
#include <fcppt/config/external_end.hpp>


awl::backends::wayland::cursor::predefined::predefined(
	awl::backends::wayland::cursor::theme const &_theme,
	awl::backends::wayland::cursor::name const &_name
)
:
	impl_{
		::wl_cursor_theme_get_cursor(
			_theme.get(),
			_name.get().c_str()
		)
	}
{
	if(
		impl_
		==
		nullptr
	)
		throw
			awl::exception{
				FCPPT_TEXT("Getting a cursor with name ")
				+
				fcppt::from_std_string(
					_name.get()
				)
				+
				FCPPT_TEXT(" failed")
			};
}

awl::backends::wayland::cursor::predefined::~predefined()
{
}

awl::backends::wayland::cursor::optional
awl::backends::wayland::cursor::predefined::get() const
{
	return
		awl::backends::wayland::cursor::optional{
			impl_
		};
}
