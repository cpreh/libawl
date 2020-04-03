#include <awl/backends/x11/deleter.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/backends/x11/window/get_class_hint.hpp>
#include <awl/backends/x11/window/optional_class_hint.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <string>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::optional_class_hint
awl::backends::x11::window::get_class_hint(
	awl::backends::x11::display const &_display,
	Window const _window
)
{
	XClassHint data;

	if(
		::XGetClassHint(
			_display.get(),
			_window,
			&data
		)
		==
		0
	)
	{
		return
			awl::backends::x11::window::optional_class_hint{};
	}

	using
	char_holder
	=
	fcppt::unique_ptr<
		char,
		awl::backends::x11::deleter
	>;

	char_holder const res1(
		data.res_name
	);

	char_holder const res2(
		data.res_class
	);

	return
		awl::backends::x11::window::optional_class_hint{
			awl::backends::x11::window::class_hint{
				awl::backends::x11::window::class_hint::res_name_type{
					std::string(
						data.res_name
					)
				},
				awl::backends::x11::window::class_hint::res_class_type{
					std::string(
						data.res_class
					)
				}
			}
		};
}
