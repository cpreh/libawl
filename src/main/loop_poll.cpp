#include <awl/main/exit_code.hpp>
#include <awl/main/loop.hpp>
#include <awl/main/loop_callback.hpp>
#include <awl/main/loop_poll.hpp>
#include <awl/main/loop_process_callback.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/processor.hpp>


awl::main::exit_code
awl::main::loop_poll(
	awl::system::event::processor &_processor,
	awl::main::loop_callback const &_callback
)
{
	return
		awl::main::loop(
			awl::main::loop_process_callback{
				[
					&_processor
				]{
					return
						_processor.poll();
				}
			},
			_callback
		);
}
