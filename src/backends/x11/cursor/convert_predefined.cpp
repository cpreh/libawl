#include <awl/backends/x11/cursor/convert_predefined.hpp>
#include <awl/backends/x11/cursor/shape.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/cursorfont.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::shape
awl::backends::x11::cursor::convert_predefined(
	awl::cursor::type const _type
)
{
	switch(
		_type
	)
	{
	case awl::cursor::type::arrow:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape,
				fcppt::cast::to_unsigned_fun
			>(
				XC_left_ptr
			);
	case awl::cursor::type::cross:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape,
				fcppt::cast::to_unsigned_fun
			>(
				XC_cross
			);
	case awl::cursor::type::hand:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape,
				fcppt::cast::to_unsigned_fun
			>(
				XC_hand1
			);
	}

	FCPPT_ASSERT_UNREACHABLE;
}
