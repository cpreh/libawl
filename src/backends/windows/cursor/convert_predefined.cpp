#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/convert_predefined.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/char_type.hpp>
#include <fcppt/assert/unreachable.hpp>


fcppt::char_type const *
awl::backends::windows::cursor::convert_predefined(
	awl::cursor::type const _type
)
{
	switch(
		_type
	)
	{
	case awl::cursor::type::arrow:
		return
			IDC_ARROW;
	case awl::cursor::type::cross:
		return
			IDC_CROSS;
	case awl::cursor::type::hand:
		return
			IDC_HAND;
	case awl::cursor::type::icon:
		return
			IDC_ICON;
	case awl::cursor::type::invisible:
		// TODO: Better typing
		break;
	}

	FCPPT_ASSERT_UNREACHABLE;
}
