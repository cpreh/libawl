#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/loop_function.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/result.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/either/loop.hpp>


awl::main::exit_code
awl::main::loop_next(
	awl::system::event::processor &_processor,
	awl::main::loop_function const &_function
)
{
	return
		fcppt::either::loop(
			[
				&_processor
			]{
				return
					_processor.next();
			},
			[
				&_function
			](
				awl::event::container const &_events
			)
			{
				fcppt::algorithm::loop(
					_events,
					[
						&_function
					](
						awl::event::base_unique_ptr const &_event
					)
					{
						_function(
							*_event
						);
					}
				);
			}
		);
}
