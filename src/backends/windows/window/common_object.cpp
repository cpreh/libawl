#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/post_message.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/get_client_rect.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/rect.hpp>
#include <awl/window/unit.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/size_fun.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/cast/try_dynamic.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>


awl::backends::windows::window::common_object::common_object()
:
	awl::backends::windows::window::object()
{
}

awl::backends::windows::window::common_object::~common_object()
{
}

awl::window::dim
awl::backends::windows::window::common_object::size() const
{
	return
		fcppt::math::dim::to_unsigned(
			this->rect().size()
		);
}

awl::window::rect
awl::backends::windows::window::common_object::rect() const
{
	RECT const ret(
		fcppt::optional::to_exception(
			awl::backends::windows::window::get_client_rect(
				*this
			),
			[]{
				return
					awl::exception{
						FCPPT_TEXT("Can't get the window size because GetWindowRect failed!")
					};
			}
		)
	);

	return
		awl::window::rect(
			awl::window::rect::vector(
				fcppt::cast::size<
					awl::window::unit
				>(
					ret.left
				),
				fcppt::cast::size<
					awl::window::unit
				>(
					ret.top
				)
			),
			awl::window::rect::dim(
				fcppt::cast::size<
					awl::window::unit
				>(
					ret.right - ret.left
				),
				fcppt::cast::size<
					awl::window::unit
				>(
					ret.bottom - ret.top
				)
			)
		);
}

void
awl::backends::windows::window::common_object::show()
{
	BOOL const prev_visible(
		::ShowWindow(
			this->hwnd(),
			SW_SHOWDEFAULT
		)
	);

	if(
		prev_visible != 0
	)
		return;

	awl::window::dim const cur_size(
		this->size()
	);

	awl::backends::windows::event::post_message(
		this->hwnd(),
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::event::type,
			fcppt::cast::to_unsigned_fun
		>(
			WM_SIZE
		),
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::event::wparam,
			fcppt::cast::size_fun
		>(
			fcppt::cast::to_unsigned(
				SIZE_RESTORED
			)
		),
		awl::backends::windows::event::lparam(
			MAKELPARAM(
				fcppt::cast::size<
					WORD
				>(
					cur_size.w()
				),
				fcppt::cast::size<
					WORD
				>(
					cur_size.h()
				)
			)
		)
	);
}

bool
awl::backends::windows::window::common_object::equal_to(
	awl::window::object const &_other
) const
{
	return
		fcppt::optional::maybe(
			fcppt::cast::try_dynamic<
				awl::backends::windows::window::object const &
			>(
				_other
			),
			[]
			{
				return
					false;
			},
			[
				this
			](
				awl::backends::windows::window::object const &_casted_other
			)
			{
				return
					_casted_other.hwnd()
					==
					this->hwnd();
			}
		);
}
