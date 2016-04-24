#include <awl/main/exit_code.hpp>
#include <awl/main/loop.hpp>
#include <awl/main/loop_callback.hpp>
#include <awl/main/loop_process_callback.hpp>
#include <awl/main/optional_exit_code.hpp>


awl::main::exit_code
awl::main::loop(
	awl::main::loop_process_callback const &_process,
	awl::main::loop_callback const &_loop
)
{
	// TODO: This is ugly
	for(
		;;
	)
	{
		awl::main::optional_exit_code const code{
			_process()
		};

		if(
			code.has_value()
		)
			return
				code.get_unsafe();

		_loop();
	}
}
