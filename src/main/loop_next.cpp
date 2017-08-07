#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/loop_function.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/result.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/variant/match.hpp>


awl::main::exit_code
awl::main::loop_next(
	awl::system::event::processor &_processor,
	awl::main::loop_function const &_function
)
{
	// TODO!
	awl::main::optional_exit_code code;

	while(
		!code.has_value()
	)
	{
		fcppt::variant::match(
			_processor.next(),
			[
				&code
			](
				awl::main::exit_code const _code
			)
			{
				code =
					awl::main::optional_exit_code{
						_code
					};
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

	return
		code.get_unsafe();
}
