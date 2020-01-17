#include <awl/show_error_narrow.hpp>
#include <fcppt/config/platform.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/backends/windows/message_box_narrow.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#else
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>
#endif


void
awl::show_error_narrow(
	std::string const &_text
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	awl::backends::windows::message_box_narrow(
		awl::backends::windows::window::const_optional_object_ref(),
		_text,
		"Error",
		MB_OK | MB_ICONERROR
	);
#else
	std::cerr
		<< _text
		<< '\n';
#endif
}
