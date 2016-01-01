#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/adjusted_size.hpp>
#include <awl/backends/windows/window/signed_dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>


awl::backends::windows::window::signed_dim
awl::backends::windows::window::adjusted_size(
	awl::window::optional_dim const &_opt_dim,
	DWORD const _flags
)
{
	return
		fcppt::optional::maybe(
			_opt_dim,
			[]{
				return
					awl::backends::windows::window::signed_dim(
						CW_USEDEFAULT,
						CW_USEDEFAULT
					);
			},
			[
				_flags
			](
				awl::window::dim const _dim
			)
			{
				RECT rect =
				{
					0,
					0,
					fcppt::cast::to_signed(
						_dim.w()
					),
					fcppt::cast::to_signed(
						_dim.h()
					)
				};

				if(
					!::AdjustWindowRect(
						&rect,
						_flags,
						FALSE
					)
				)
					throw awl::exception(
						FCPPT_TEXT("AdjustWindowRect() failed!")
					);

				return
					awl::backends::windows::window::signed_dim(
						fcppt::cast::size<
							awl::backends::windows::window::signed_dim::value_type
						>(
							rect.right - rect.left
						),
						fcppt::cast::size<
							awl::backends::windows::window::signed_dim::value_type
						>(
							rect.bottom - rect.top
						)
					);
			}
		);
}
