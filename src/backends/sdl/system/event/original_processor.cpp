#include <awl/backends/sdl/system/event/original_processor.hpp>
#include <awl/backends/sdl/system/event/processor.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>


awl::backends::sdl::system::event::original_processor::original_processor()
:
	awl::backends::sdl::system::event::processor{}
{
}

awl::backends::sdl::system::event::original_processor::~original_processor()
{
}

awl::system::event::result
awl::backends::sdl::system::event::original_processor::poll()
{
}

awl::system::event::result
awl::backends::sdl::system::event::original_processor::next()
{
}

void
awl::backends::sdl::system::event::original_processor::quit(
	awl::main::exit_code
)
{
}

awl::timer::unique_ptr
awl::backends::sdl::system::event::original_processor::create_timer(
	awl::timer::setting const &
)
{
}
