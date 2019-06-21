#include <awl/backends/sdl/timer/object.hpp>
#include <awl/backends/sdl/system/event/original_processor.hpp>
#include <awl/backends/sdl/system/event/processor.hpp>
#include <awl/backends/sdl/system/event/register.hpp>
#include <awl/exception.hpp>
#include <awl/event/base.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/to_exception.hpp>


awl::backends::sdl::system::event::original_processor::original_processor()
:
	awl::backends::sdl::system::event::processor{},
	timer_event_{
		fcppt::optional::to_exception(
			awl::backends::sdl::system::event::register_(),
			[]{
				return
					awl::exception{
						FCPPT_TEXT("Unable to register SDL timer event!")
					};
			}
		)
	}
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
	awl::main::exit_code const _code
)
{
}

awl::timer::unique_ptr
awl::backends::sdl::system::event::original_processor::create_timer(
	awl::timer::setting const &_setting
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::timer::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::sdl::timer::object
			>(
				_setting,
				this->timer_event_
			)
		);
}
