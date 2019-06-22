#include <awl/exception.hpp>
#include <awl/backends/sdl/system/event/original_processor.hpp>
#include <awl/backends/sdl/system/event/poll.hpp>
#include <awl/backends/sdl/system/event/processor.hpp>
#include <awl/backends/sdl/system/event/register.hpp>
#include <awl/backends/sdl/system/event/translate.hpp>
#include <awl/backends/sdl/system/event/wait.hpp>
#include <awl/backends/sdl/timer/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/const.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/container/join.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/loop.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <utility>
#include <fcppt/config/external_end.hpp>


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
	},
	exit_code_{}
{
}

awl::backends::sdl::system::event::original_processor::~original_processor()
{
}

awl::system::event::result
awl::backends::sdl::system::event::original_processor::poll()
{
	return
		this->process(
			awl::backends::sdl::system::event::original_processor::process_function{
				[
					this
				]{
					return
						this->process_events();
				}
			}
		);
}

awl::system::event::result
awl::backends::sdl::system::event::original_processor::next()
{
	return
		this->process(
			awl::backends::sdl::system::event::original_processor::process_function{
				[
					this
				]{
					awl::event::base_unique_ptr event{
						this->translate(
							awl::backends::sdl::system::event::wait()
						)
					};

					return
						fcppt::container::join(
							fcppt::container::make<
								awl::event::container
							>(
								std::move(
									event
								)
							),
							this->process_events()
						);
				}
			}
		);
}

void
awl::backends::sdl::system::event::original_processor::quit(
	awl::main::exit_code const _code
)
{
	this->exit_code_ =
		awl::main::optional_exit_code{
			_code
		};
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

awl::system::event::result
awl::backends::sdl::system::event::original_processor::process(
	process_function const &_function
)
{
	return
		fcppt::optional::maybe(
			this->exit_code_,
			[
				&_function
			]{
				return
					awl::system::event::result{
						_function()
					};
			},
			[](
				awl::main::exit_code const _code
			)
			{
				return
					awl::system::event::result{
						_code
					};
			}
		);
}

awl::event::container
awl::backends::sdl::system::event::original_processor::process_events()
{
	awl::event::container result{};

	fcppt::either::loop(
		[]{
			return
				fcppt::either::from_optional(
					awl::backends::sdl::system::event::poll(),
					fcppt::const_(
						fcppt::unit{}
					)
				);
		},
		[
			this,
			&result
		](
			SDL_Event const &_event
		)
		{
			result.push_back(
				this->translate(
					_event
				)
			);
		}
	);

	return
		result;
}


awl::event::base_unique_ptr
awl::backends::sdl::system::event::original_processor::translate(
	SDL_Event const &_event
) const
{
	return
		awl::backends::sdl::system::event::translate(
			this->timer_event_,
			_event
		);
}
