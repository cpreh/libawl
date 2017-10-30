#include <awl/exception.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/post_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/visual/object.hpp>
#include <awl/backends/windows/window/create.hpp>
#include <awl/backends/windows/window/get_client_rect.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/backends/windows/window/set_user_data.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/unit.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/size_fun.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>
#include <fcppt/optional/static_cast.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

awl::backends::windows::window::original_object::original_object(
	awl::window::parameters const &_parameters,
	awl::backends::windows::wndclass &_wndclass,
	awl::event::container_reference const _events,
	awl::backends::windows::wndclass_remove_callback const &_remove_wndclass
)
:
	awl::backends::windows::window::object(),
	visual_(
		_parameters.visual()
	),
	holder_(
		awl::backends::windows::window::create(
			_parameters,
			_wndclass
		),
		_remove_wndclass
	),
	cursor_(
		fcppt::optional::static_cast_<
			awl::backends::windows::cursor::object const
		>(
			_parameters.cursor()
		)
	),
	user_data_{
		fcppt::reference_to_base<
			awl::backends::windows::window::object
		>(
			fcppt::make_ref(
				*this
			)
		),
		_events
	}
{
	fcppt::cast::static_downcast<
		awl::backends::windows::visual::object const &
	>(
		_parameters.visual()
	).apply(
		this->hwnd()
	);

	awl::backends::windows::window::set_user_data(
		this->hwnd(),
		user_data_
	);
}

FCPPT_PP_POP_WARNING

awl::backends::windows::window::original_object::~original_object()
{
	// FIXME: Where do we have to do this before we can destroy the cursor?
	if(
		cursor_.has_value()
	)
		::SetCursor(
			nullptr
		);
}

awl::window::dim
awl::backends::windows::window::original_object::size() const
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
		fcppt::math::dim::to_unsigned(
			fcppt::math::dim::static_<
				awl::window::unit,
				2
			>{
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
			}
		);
}

void
awl::backends::windows::window::original_object::show()
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

	awl::backends::windows::post_message(
		this->hwnd(),
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::message_type,
			fcppt::cast::to_unsigned_fun
		>(
			WM_SIZE
		),
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::wparam,
			fcppt::cast::size_fun
		>(
			fcppt::cast::to_unsigned(
				SIZE_RESTORED
			)
		),
		awl::backends::windows::lparam{
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
		}
	);
}

awl::visual::object const &
awl::backends::windows::window::original_object::visual() const
{
	return
		visual_;
}

HWND
awl::backends::windows::window::original_object::hwnd() const
{
	return
		holder_.get();
}

awl::backends::windows::cursor::const_optional_object_ref
awl::backends::windows::window::original_object::cursor() const
{
	return
		cursor_;
}
