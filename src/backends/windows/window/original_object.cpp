#include <awl/exception.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/post_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/visual/object.hpp>
#include <awl/backends/windows/window/create.hpp>
#include <awl/backends/windows/window/get_client_rect.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/unit.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/size_fun.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/optional/static_cast.hpp>



awl::backends::windows::window::original_object::original_object(
	awl::window::parameters const &_param,
	awl::backends::windows::system::event::original_processor &_system_processor,
	awl::backends::windows::wndclass &_wndclass,
	awl::backends::windows::wndclass_remove_callback const &_remove_wndclass
)
:
	awl::backends::windows::window::object(),
	awl::window::object(),
	visual_(
		_param.visual()
	),
	holder_(
		awl::backends::windows::window::create(
			_param,
			_wndclass
		),
		_remove_wndclass
	),
	cursor_(
		fcppt::optional::static_cast_<
			awl::backends::windows::cursor::object const
		>(
			_param.cursor()
		)
	),
	processor_{
		fcppt::unique_ptr_to_base<
			awl::backends::windows::window::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::window::event::original_processor
			>(
				*this
			)
		)
	},
	scoped_processor_{
		_system_processor,
		*this,
		*processor_
	}
{
	fcppt::cast::static_downcast<
		awl::backends::windows::visual::object const &
	>(
		_param.visual()
	).apply(
		this->hwnd()
	);
}

awl::backends::windows::window::original_object::~original_object()
{
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

awl::window::event::processor &
awl::backends::windows::window::original_object::processor()
{
	return
		*processor_;
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
