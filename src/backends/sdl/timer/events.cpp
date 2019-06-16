#include <awl/backends/sdl/timer/events.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <fcppt/move_clear.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::timer::events::events()
:
	events_{}
{
}

awl::backends::sdl::timer::events::~events()
{
}

void
awl::backends::sdl::timer::events::push_back(
	awl::event::base_unique_ptr &&_event
)
{
	events_.push_back(
		std::move(
			_event
		)
	);
}

awl::event::container
awl::backends::sdl::timer::events::get()
{
	return
		fcppt::move_clear(
			this->events_
		);
}
