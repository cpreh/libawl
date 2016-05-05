#include <awl/log.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/main/loop_callback.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/activate_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
	fcppt::log::activate_levels(
		awl::log(),
		fcppt::log::level::debug
	);

	awl::system::object_unique_ptr const window_system(
		awl::system::create()
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
			.size(
				awl::window::dim(
					1024u,
					768u
				)
			)
		)
	);

	window->show();

	awl::system::event::processor &system_processor(
		window_system->processor()
	);

	fcppt::signal::auto_connection const resize_connection(
		window->processor().resize_callback(
			awl::window::event::resize_callback(
				[](
					awl::window::event::resize const &_size
				)
				{
					fcppt::io::cout()
						<< FCPPT_TEXT("Resize: ")
						<< _size.dim()
						<< FCPPT_TEXT('\n');
				}
			)
		)
	);

	fcppt::signal::auto_connection const destroy_connection(
		window->processor().destroy_callback(
			awl::window::event::destroy_callback(
				[
					&system_processor
				](
					awl::window::event::destroy const &
				){
					system_processor.quit(
						awl::main::exit_success()
					);
				}
			)
		)
	);

	return
		awl::main::loop_next(
			system_processor,
			awl::main::loop_callback{
				[]{}
			}
		).get();
}
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<< _exception.string()
		<< FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
