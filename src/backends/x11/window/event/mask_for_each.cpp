#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/mask_for_each.hpp>
#include <awl/backends/x11/window/event/mask_function.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/shifted_mask_c.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

void awl::backends::x11::window::event::mask_for_each(
    awl::backends::x11::window::event::mask const _mask,
    awl::backends::x11::window::event::mask_function const &_mask_function)
{
  fcppt::algorithm::loop(
      fcppt::mpl::list::interval<
          std::integral_constant<int, 0>,
          std::integral_constant<
              int,
              std::numeric_limits<awl::backends::x11::window::event::mask::value_type>::digits>>{},
      [_mask, &_mask_function](auto const _index)
      {
        FCPPT_USE(_index);

        using index = fcppt::tag_type<decltype(_index)>;

        fcppt::bit::mask<awl::backends::x11::window::event::mask::value_type> const mask_bit{
            fcppt::bit::shifted_mask_c<
                awl::backends::x11::window::event::mask::value_type,
                index::value>()};

        if (fcppt::bit::test(_mask.get(), mask_bit))
        {
          _mask_function(awl::backends::x11::window::event::mask_bit{mask_bit.get()});
        }
      });
}
