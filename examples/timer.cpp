#include <awl/event/base_fwd.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/main/loop_function.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/timer/delay.hpp>
#include <awl/timer/duration.hpp>
#include <awl/timer/match.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/period.hpp>
#include <awl/timer/setting.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
	fcppt::log::context log_context{
		fcppt::log::optional_level{
			fcppt::log::level::debug
		},
		fcppt::log::default_level_streams()
	};

	awl::system::object_unique_ptr const window_system(
		awl::system::create(
			log_context
		)
	);

	awl::visual::object_unique_ptr const visual(
		window_system->default_visual()
	);

	awl::window::object_unique_ptr const window(
		window_system->create_window(
			awl::window::parameters(
				*visual
			)
			.title(
				FCPPT_TEXT("awltest")
			)
			.class_name(
				FCPPT_TEXT("awltest")
			)
		)
	);

	window->show();

	awl::system::event::processor &system_processor(
		window_system->processor()
	);

	awl::timer::unique_ptr const timer{
		system_processor.create_timer(
			awl::timer::setting{
				awl::timer::delay{
					std::chrono::duration_cast<
						awl::timer::duration
					>(
						std::chrono::seconds{
							2
						}
					)
				},
				awl::timer::period{
					std::chrono::duration_cast<
						awl::timer::duration
					>(
						std::chrono::seconds{
							1
						}
					)
				}
			}
		)
	};

	unsigned timer_fired{
		0u
	};

	return
		awl::main::loop_next(
			system_processor,
			awl::main::loop_function{
				[
					&timer_fired,
					&timer,
					&system_processor
				](
					awl::event::base const &_event
				){
					if(
						awl::timer::match(
							_event,
							*timer
						)
					)
					{
						++timer_fired;

						fcppt::io::cout()
							<<
							FCPPT_TEXT("Timer event ")
							<<
							timer_fired
							<<
							FCPPT_TEXT('\n');
					}

					if(
						timer_fired
						==
						3u
					)
						system_processor.quit(
							awl::main::exit_success()
						);
				}
			}
		).get();
}
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<<
		_exception.string()
		<<
		FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
