#include <awl/config.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/exit_failure.hpp>
#if defined(AWL_X11_BACKEND) || defined(AWL_WAYLAND_BACKEND)
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>
#endif


awl::main::exit_code
awl::main::exit_failure()
{
	return
		awl::main::exit_code(
#if defined(AWL_X11_BACKEND) || defined(AWL_WAYLAND_BACKEND)
			EXIT_FAILURE
#elif defined(AWL_WINDOWS_BACKEND)
			0 // TODO: what do we return here?
#else
#error "Don't know what exit_failure should be"
#endif
		);
}
