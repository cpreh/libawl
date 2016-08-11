#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/mask_callback.hpp>
#include <awl/backends/x11/window/event/mask_for_each.hpp>
#include <fcppt/use.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/shifted_mask_c.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/range_c.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::window::event::mask_for_each(
	awl::backends::x11::window::event::mask const _mask,
	awl::backends::x11::window::event::mask_callback const &_mask_callback
)
{
	fcppt::algorithm::loop(
		boost::mpl::range_c<
			int,
			0,
			std::numeric_limits<
				awl::backends::x11::window::event::mask::value_type
			>::digits
		>{},
		[
			_mask,
			&_mask_callback
		](
			auto const _index
		)
		{
			FCPPT_USE(
				_index
			);

			typedef
			fcppt::tag_type<
				decltype(
					_index
				)
			>
			index;

			fcppt::bit::mask<
				awl::backends::x11::window::event::mask::value_type
			> const mask_bit{
				fcppt::bit::shifted_mask_c<
					awl::backends::x11::window::event::mask::value_type,
					index::value
				>()
			};

			if(
				fcppt::bit::test(
					_mask.get(),
					mask_bit
				)
			)
				_mask_callback(
					awl::backends::x11::window::event::mask_bit{
						mask_bit.get()
					}
				);
		}
	);
}
