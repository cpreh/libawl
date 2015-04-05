#include <awl/exception.hpp>
#include <awl/backends/x11/window/size_hints.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <fcppt/maybe_void.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::size_hints::size_hints(
	awl::window::optional_dim const &_exact_hint,
	awl::window::optional_dim const &_minimum_hint,
	awl::window::optional_dim const &_maximum_hint
)
:
	hints_(
		::XAllocSizeHints()
	)
{
	if(
		!hints_
	)
		throw awl::exception(
			FCPPT_TEXT("XAllocSizeHints() failed!")
		);

	hints_->flags = 0;

	fcppt::maybe_void(
		_exact_hint,
		[
			this
		](
			awl::window::dim const _hint
		)
		{
			hints_->base_width =
				fcppt::cast::to_signed(
					_hint.w()
				);

			hints_->base_height =
				fcppt::cast::to_signed(
					_hint.h()
				);

			hints_->flags |= PSize;
		}
	);

	fcppt::maybe_void(
		_minimum_hint,
		[
			this
		](
			awl::window::dim const _hint
		)
		{
			hints_->min_width =
				fcppt::cast::to_signed(
					_hint.w()
				);

			hints_->min_height =
				fcppt::cast::to_signed(
					_hint.h()
				);

			hints_->flags |= PMinSize;
		}
	);

	fcppt::maybe_void(
		_maximum_hint,
		[
			this
		](
			awl::window::dim const _hint
		)
		{
			hints_->max_width =
				fcppt::cast::to_signed(
					_hint.w()
				);

			hints_->max_height =
				fcppt::cast::to_signed(
					_hint.h()
				);

			hints_->flags |= PMaxSize;
		}
	);
}

XSizeHints *
awl::backends::x11::window::size_hints::get() const
{
	return
		hints_.get();
}

awl::backends::x11::window::size_hints::~size_hints()
{
}
