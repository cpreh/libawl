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
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <awl/window/event/show_callback.hpp>
#include <awl/window/event/show_fwd.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
	awl::system::object_unique_ptr const system(
		awl::system::create()
	);

	awl::visual::object_unique_ptr const visual(
		system->default_visual()
	);

	awl::window::object_unique_ptr const window(
		system->create_window(
			awl::window::parameters(
				*visual
			)
			.class_name(
				FCPPT_TEXT("awlshow")
			)
			.size(
				awl::window::dim(
					1024u,
					768U
				)
			)
		)
	);

	awl::system::event::processor &system_processor(
		system->processor()
	);

	awl::window::event::processor_unique_ptr const window_processor(
		system_processor.create_window_processor(
			*window
		)
	);

	window->show();

	fcppt::signal::auto_connection const show_connection(
		window_processor->show_callback(
			awl::window::event::show_callback(
				[
					&system_processor
				](
					awl::window::event::show const &
				)
				{
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
